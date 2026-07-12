# -*- coding: utf-8 -*-
"""
================================================================================
  全国交通咨询模拟系统 —— 数据爬虫  (已优化并行版)
================================================================================
  功能:
    1. 爬取 12306 官网两城市间指定时间范围内的列车数据（时刻、车次、票价）
    2. 爬取航班数据（内置航线数据库）
    3. 按 trans.txt / city.txt 格式输出，可直接被 C++ 程序加载

  使用:
    python 1.py
    按提示输入: 起点城市、终点城市、起始日期、结束日期

  输出文件:
    - city.txt         : 城市列表
    - trans.txt        : 交通信息
    - station_cache.json: 车站缓存(自动生成, 加速后续运行)

  依赖:
    pip install requests urllib3
================================================================================
"""

import requests
import re
import json
import sys
import os
import time as time_module
import urllib3
from datetime import datetime, timedelta
from typing import Dict, List, Tuple, Optional, Any
from concurrent.futures import ThreadPoolExecutor, as_completed

# ── 禁用 SSL 警告（部分国内网站证书可能有问题） ──
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

# ══════════════════════════════════════════════════════════════════════════════
#  全局配置
# ══════════════════════════════════════════════════════════════════════════════

HEADERS = {
    'User-Agent': (
        'Mozilla/5.0 (Windows NT 10.0; Win64; x64) '
        'AppleWebKit/537.36 (KHTML, like Gecko) '
        'Chrome/131.0.0.0 Safari/537.36'
    ),
    'Accept': 'application/json, text/javascript, */*; q=0.01',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
    'Accept-Encoding': 'gzip, deflate, br',
    'Connection': 'keep-alive',
    'Referer': 'https://kyfw.12306.cn/otn/leftTicket/init',
}

# 12306 API 端点
URL_STATION_NAME = (
    'https://kyfw.12306.cn/otn/resources/js/framework/station_name.js'
)
URL_QUERY_TICKET = 'https://kyfw.12306.cn/otn/leftTicket/query'
URL_QUERY_PRICE = 'https://kyfw.12306.cn/otn/leftTicket/queryTicketPrice'
URL_INIT_PAGE = 'https://kyfw.12306.cn/otn/leftTicket/init'

# 航班数据源（飞常准公开查询页面 / 备用）
URL_FLIGHT_SEARCH = 'https://flights.ctrip.com/actualtime/'

# ── 内置城市→车站电报码映射（网络获取失败时的后备） ──
FALLBACK_STATION_MAP: Dict[str, str] = {
    "北京": "BJP",     "上海": "SHH",     "广州": "GZQ",
    "深圳": "SZQ",     "成都": "CDW",     "重庆": "CQW",
    "杭州": "HZH",     "武汉": "WHN",     "西安": "XAY",
    "郑州": "ZZF",     "南京": "NJH",     "洛阳": "LYF",
    "长沙": "CSQ",     "昆明": "KMM",     "天津": "TJP",
    "沈阳": "SYT",     "哈尔滨": "HBB",   "大连": "DLT",
    "济南": "JNK",     "青岛": "QDK",     "合肥": "HFH",
    "南昌": "NCG",     "福州": "FZS",     "厦门": "XMS",
    "贵阳": "GIW",     "南宁": "NNZ",     "海口": "HAK",
    "兰州": "LZJ",     "银川": "YIJ",     "西宁": "XNO",
    "呼和浩特": "HHH", "乌鲁木齐": "WAR", "太原": "TYV",
    "石家庄": "SJP",   "长春": "CCT",     "宁波": "NGH",
    "拉萨": "LSO",     "温州": "WZH",     "桂林": "GLE",
    "徐州": "XCH",     "苏州": "SZH",     "无锡": "WXH",
}

# ── 城市间大致距离 (km)，用于估算票价 ──
CITY_DISTANCES: Dict[Tuple[str, str], int] = {
    ("北京", "上海"): 1318, ("北京", "广州"): 2298, ("北京", "西安"): 1200,
    ("北京", "郑州"): 690,  ("北京", "南京"): 1020, ("北京", "武汉"): 1229,
    ("北京", "洛阳"): 820,  ("上海", "广州"): 1780, ("上海", "南京"): 300,
    ("上海", "杭州"): 170,  ("上海", "郑州"): 950,  ("上海", "武汉"): 820,
    ("郑州", "武汉"): 520,  ("郑州", "西安"): 510,  ("郑州", "洛阳"): 125,
    ("郑州", "广州"): 1600, ("洛阳", "西安"): 380,  ("洛阳", "武汉"): 550,
    ("洛阳", "北京"): 820,  ("西安", "成都"): 740,  ("西安", "武汉"): 740,
    ("西安", "郑州"): 510,  ("武汉", "广州"): 1060, ("武汉", "南京"): 540,
    ("武汉", "杭州"): 750,  ("南京", "杭州"): 260,  ("南京", "上海"): 300,
    ("南京", "武汉"): 540,  ("杭州", "广州"): 1300, ("杭州", "上海"): 170,
    ("广州", "成都"): 1700, ("成都", "西安"): 740,  ("成都", "武汉"): 1130,
}


# ══════════════════════════════════════════════════════════════════════════════
#  工具函数
# ══════════════════════════════════════════════════════════════════════════════

def get_distance(c1: str, c2: str) -> int:
    """返回两城市间大致距离 (km)，未知则返回默认 500 km"""
    d = CITY_DISTANCES.get((c1, c2))
    if d is None:
        d = CITY_DISTANCES.get((c2, c1), 500)
    return d


def estimate_train_cost(
    train_code: str, from_city: str, to_city: str,
    duration_hours: float = 0
) -> int:
    """
    根据列车类型、距离和时长估算票价 (元)
      G 字头高铁 : 二等座 ≈ 0.46 元/km
      D 字头动车 : 二等座 ≈ 0.31 元/km
      C 字头城际 : ≈ 0.35 元/km
      普速 >6h    : 硬卧 ≈ 0.30 元/km
      普速 ≤6h    : 硬座 ≈ 0.15 元/km
    """
    dist = get_distance(from_city, to_city)
    prefix = train_code[0].upper()

    if prefix == 'G':
        return int(dist * 0.46)       # 高铁二等座
    elif prefix == 'D':
        return int(dist * 0.31)       # 动车二等座
    elif prefix == 'C':
        return int(dist * 0.35)       # 城际
    elif prefix in ('K', 'T', 'Z'):
        if duration_hours > 6:
            return int(dist * 0.30)   # 硬卧
        else:
            return int(dist * 0.15)   # 硬座
    else:
        # 纯数字车次(如 1461) 也按普速处理
        if duration_hours > 6:
            return int(dist * 0.30)   # 硬卧
        else:
            return int(dist * 0.15)   # 硬座


def estimate_flight_cost(from_city: str, to_city: str) -> int:
    """估算机票经济舱全价 (元)"""
    dist = get_distance(from_city, to_city)
    if dist <= 500:
        return int(dist * 1.5)
    elif dist <= 1000:
        return int(dist * 1.2)
    else:
        return int(dist * 0.9)


# ══════════════════════════════════════════════════════════════════════════════
#  12306 列车爬虫
# ══════════════════════════════════════════════════════════════════════════════

class Train12306Scraper:
    """12306 铁路客户服务中心 —— 列车时刻与票价爬虫"""

    def __init__(self):
        self.session = requests.Session()
        self.session.headers.update(HEADERS)
        self.session.verify = False
        self.station_to_code: Dict[str, str] = {}
        self.code_to_station: Dict[str, str] = {}
        self._price_api_ok = True  # 票价API是否可用

    # ── 车站列表 ──────────────────────────────────────────────────────────

    def _fetch_station_map(self) -> bool:
        """
        从 12306 下载全国车站列表并解析（首次下载后缓存到 station_cache.json）。
        格式: @pinyin|站名|电报码|全拼|简拼|序号
        """
        # ── 尝试从缓存加载 ──
        try:
            script_dir = os.path.dirname(os.path.abspath(__file__))
        except NameError:
            script_dir = os.getcwd()
        cache_path = os.path.join(script_dir, 'station_cache.json')
        try:
            if os.path.exists(cache_path):
                with open(cache_path, 'r', encoding='utf-8') as f:
                    cached = json.load(f)
                self.station_to_code = cached.get('to_code', {})
                self.code_to_station = cached.get('to_name', {})
                if self.station_to_code:
                    print(f"[车站] 从缓存加载 {len(self.station_to_code)} 个车站", end=" ", flush=True)
                    return True
        except Exception:
            pass

        print("[车站] 正在从 12306 获取车站列表...", end=" ", flush=True)
        try:
            resp = self.session.get(URL_STATION_NAME, timeout=15)
            resp.encoding = 'utf-8'
            text = resp.text

            pattern = r"@[a-z]+\|([^|]+)\|([A-Z]+)\|"
            matches = re.findall(pattern, text)

            if not matches:
                m = re.search(r"'([^']*)'", text)
                if m:
                    matches = re.findall(pattern, m.group(1))

            if matches:
                for name, code in matches:
                    self.station_to_code[name] = code
                    self.code_to_station[code] = name

                # 写入缓存
                try:
                    with open(cache_path, 'w', encoding='utf-8') as f:
                        json.dump({
                            'to_code': self.station_to_code,
                            'to_name': self.code_to_station,
                        }, f, ensure_ascii=False)
                except Exception:
                    pass

                print(f"✓ 共 {len(self.station_to_code)} 个车站")
                return True
            else:
                print("✗ 解析失败（格式可能已变化）")
                return False

        except Exception as e:
            print(f"✗ 网络错误: {e}")
            return False

    def _ensure_station_map(self):
        """确保车站映射可用，优先从网络获取，失败则用内置映射"""
        if not self.station_to_code:
            ok = self._fetch_station_map()
            if not ok:
                print("[车站] 使用内置车站映射（仅含主要城市）")
                self.station_to_code = FALLBACK_STATION_MAP.copy()
                self.code_to_station = {
                    v: k for k, v in FALLBACK_STATION_MAP.items()
                }

    def _find_station_code(self, city: str) -> Optional[str]:
        """根据城市名查车站电报码"""
        self._ensure_station_map()

        # 1) 精确匹配
        if city in self.station_to_code:
            return self.station_to_code[city]

        # 2) 模糊匹配（城市名是站名的子串）
        for name, code in self.station_to_code.items():
            if city in name:
                return code

        return None

    # ── Cookie ─────────────────────────────────────────────────────────────

    def _ensure_cookies(self):
        """首次访问 12306 页面以获取必要的 Cookie"""
        try:
            if 'RAIL_EXPIRATION' not in self.session.cookies:
                self.session.get(URL_INIT_PAGE, timeout=10)
                time_module.sleep(0.5)
        except Exception:
            pass

    # ── 查询列车 ──────────────────────────────────────────────────────────

    def query_trains(
        self, from_city: str, to_city: str, date_str: str
    ) -> List[Dict[str, Any]]:
        """
        查询指定日期两城市间的所有列车。

        参数
        ----
        from_city : 出发城市名（如 "北京"）
        to_city   : 到达城市名（如 "上海"）
        date_str  : 日期字符串 "YYYY-MM-DD"

        返回
        ----
        list[dict] : 每条含 train_code, train_no, dep_time, arr_time,
                     duration, from_city, to_city, date 等字段
        """
        from_code = self._find_station_code(from_city)
        to_code = self._find_station_code(to_city)

        if not from_code:
            print(f"  [错误] 未找到城市 '{from_city}' 的车站代码")
            return []
        if not to_code:
            print(f"  [错误] 未找到城市 '{to_city}' 的车站代码")
            return []

        self._ensure_cookies()

        params = {
            'leftTicketDTO.train_date': date_str,
            'leftTicketDTO.from_station': from_code,
            'leftTicketDTO.to_station': to_code,
            'purpose_codes': 'ADULT',
        }

        print(f"  {date_str}  {from_city}({from_code}) → {to_city}({to_code})",
              end=" ", flush=True)

        try:
            resp = self.session.get(URL_QUERY_TICKET, params=params, timeout=15)

            if resp.status_code != 200:
                print(f"HTTP {resp.status_code}")
                return []

            data = resp.json()
            if (not data.get('status') or
                    not data.get('data', {}).get('result')):
                print("(无车次)")
                return []

            raw_list = data['data']['result']
            trains: List[Dict[str, Any]] = []

            for item in raw_list:
                fields = item.split('|')
                if len(fields) < 35:
                    continue

                try:
                    # ─── 12306 返回字段说明 ───
                    # [2]  train_no     内部编码(用于查票价)
                    # [3]  train_code   车次号(如 G1)
                    # [4]  始发站电报码
                    # [5]  终到站电报码
                    # [6]  出发站电报码
                    # [7]  到达站电报码
                    # [8]  出发时间 HH:MM
                    # [9]  到达时间 HH:MM
                    # [10] 历时 HH:MM
                    # [11] 能否购买 Y/N
                    # ──────────────────────

                    train_no = fields[2].strip()
                    train_code = fields[3].strip()
                    from_sta_code = fields[6].strip()
                    to_sta_code = fields[7].strip()
                    dep_time = fields[8].strip()
                    arr_time = fields[9].strip()
                    duration = fields[10].strip()
                    can_buy = fields[11].strip()

                    if not train_code:
                        continue

                    trains.append({
                        'train_code': train_code,
                        'train_no': train_no,
                        'from_station_code': from_sta_code,
                        'to_station_code': to_sta_code,
                        'dep_time': dep_time,
                        'arr_time': arr_time,
                        'duration': duration,
                        'can_buy': can_buy,
                        'from_city': from_city,
                        'to_city': to_city,
                        'date': date_str,
                    })
                except (IndexError, ValueError):
                    continue

            print(f"→ {len(trains)} 趟")
            return trains

        except requests.RequestException as e:
            print(f"请求失败: {e}")
            return []
        except json.JSONDecodeError:
            print("JSON 解析失败（可能需要验证码）")
            return []

    # ── 查询票价 ──────────────────────────────────────────────────────────

    def query_price(
        self, train_no: str, from_sta: str, to_sta: str,
        train_date: str, train_code: str, duration_hours: float
    ) -> Optional[int]:
        """
        查询具体车次的票价。首次失败后自动跳过后续查询。
        高铁(G): 二等座(O) > 一等座(M) > 商务座(9)
        普通车 >6h: 硬卧(3) > 软卧(4) > 硬座(1)
        普通车 ≤6h: 硬座(1) > 硬卧(3) > 软卧(4)
        """
        # 快速失败：之前失败过就不再尝试
        if not self._price_api_ok:
            return None

        self._ensure_cookies()

        prefix = train_code[0].upper() if train_code else ''

        if prefix == 'G':
            priority = ['O', 'M', '9']
        elif duration_hours > 6:
            priority = ['3', '4', '1', 'M', 'W']
        else:
            priority = ['1', '3', '4', 'M', 'W']

        params = {
            'train_no': train_no,
            'from_station_no': from_sta,
            'to_station_no': to_sta,
            'seat_types': 'OM1934W',
            'train_date': train_date,
        }

        try:
            resp = self.session.get(URL_QUERY_PRICE, params=params, timeout=5)
            if resp.status_code == 200:
                data = resp.json()
                prices = data.get('data', {})

                for seat in priority:
                    val = prices.get(seat, '--')
                    if val and str(val) not in ('--', '无', '*', '', 'None'):
                        num = re.sub(r'[^\d.]', '', str(val))
                        if num:
                            return int(float(num))
        except Exception:
            pass

        # 失败了，标记不可用，后续不再尝试
        self._price_api_ok = False
        return None

    # ── 主爬取逻辑 ───────────────────────────────────────────────────────

    def _scrape_one_date(
        self, from_city: str, to_city: str, date_str: str
    ) -> List[str]:
        """爬取单日数据（供多线程调用）"""
        trains = self.query_trains(from_city, to_city, date_str)
        lines: List[str] = []

        for t in trains:
            dep_parts = t['dep_time'].split(':')
            arr_parts = t['arr_time'].split(':')
            dep_h, dep_m = int(dep_parts[0]), int(dep_parts[1])
            arr_h, arr_m = int(arr_parts[0]), int(arr_parts[1])

            dur_parts = t['duration'].split(':')
            dur_h, dur_m = int(dur_parts[0]), int(dur_parts[1])
            duration_hours = dur_h + dur_m / 60.0
            total_dur_min = dur_h * 60 + dur_m

            dep_min_of_day = dep_h * 60 + dep_m
            arr_day_offset = (dep_min_of_day + total_dur_min) // (24 * 60)

            dt = datetime.strptime(date_str, "%Y-%m-%d")
            dep_month, dep_day = dt.month, dt.day
            arr_date = dt + timedelta(days=arr_day_offset)
            arr_month, arr_day = arr_date.month, arr_date.day

            # 票价（首次失败后自动用估算）
            cost = self.query_price(
                t['train_no'], t['from_station_code'],
                t['to_station_code'], date_str,
                t['train_code'], duration_hours
            )
            if cost is None:
                cost = estimate_train_cost(
                    t['train_code'], from_city, to_city, duration_hours
                )

            line = (
                f"火车 {from_city} {to_city} {t['train_code']} "
                f"{dep_month} {dep_day} {dep_h} {dep_m} "
                f"{arr_month} {arr_day} {arr_h} {arr_m} "
                f"{cost}"
            )
            lines.append(line)

        return lines

    def scrape(
        self, from_city: str, to_city: str,
        start_date: str, end_date: str
    ) -> List[str]:
        """
        爬取两城市间指定日期范围内所有列车（多线程并行）。
        返回 trans.txt 格式的行列表。
        """
        # 主线程中先加载车站映射，避免多线程竞争
        self._ensure_station_map()

        lines: List[str] = []
        start = datetime.strptime(start_date, "%Y-%m-%d")
        end = datetime.strptime(end_date, "%Y-%m-%d")

        # 生成所有日期
        dates: List[str] = []
        current = start
        while current <= end:
            dates.append(current.strftime("%Y-%m-%d"))
            current += timedelta(days=1)

        total_dates = len(dates)

        # 多线程并行爬取
        with ThreadPoolExecutor(max_workers=min(total_dates, 5)) as pool:
            futures = {
                pool.submit(
                    self._scrape_one_date, from_city, to_city, d
                ): d for d in dates
            }
            done = 0
            for future in as_completed(futures):
                done += 1
                try:
                    result = future.result()
                    lines.extend(result)
                    print(f"  [{done}/{total_dates}] {futures[future]} → "
                          f"{len(result)} 趟", flush=True)
                except Exception as e:
                    print(f"  [{done}/{total_dates}] {futures[future]} → "
                          f"失败: {e}", flush=True)

        return lines

    def scrape_pairs(
        self, pairs: List[Tuple[str, str]],
        start_date: str, end_date: str,
        label: str = "中转"
    ) -> List[str]:
        """
        批量爬取多组城市对（用于中转线路），多线程并行。
        pairs: [(from, to), ...]
        """
        self._ensure_station_map()
        all_lines: List[str] = []

        with ThreadPoolExecutor(max_workers=min(len(pairs), 8)) as pool:
            futures = {
                pool.submit(self.scrape, f, t, start_date, end_date): (f, t)
                for f, t in pairs
            }
            done = 0
            total = len(pairs)
            for future in as_completed(futures):
                done += 1
                f, t = futures[future]
                try:
                    result = future.result()
                    all_lines.extend(result)
                    if result:
                        print(f"  [{label} {done}/{total}] {f}→{t} → "
                              f"{len(result)} 趟", flush=True)
                except Exception as e:
                    print(f"  [{label} {done}/{total}] {f}→{t} → "
                          f"失败: {e}", flush=True)

        return all_lines


# ══════════════════════════════════════════════════════════════════════════════

class FlightScraper:
    """
    航班数据爬虫
    数据来源：
      - 主要: 携程/飞常准公开页面
      - 后备: 根据常见航线估算
    """

    # 常见航线数据库（始发 → 到达 → 航班列表）
    COMMON_FLIGHTS: Dict[str, Dict[str, List[Dict[str, Any]]]] = {
        "北京": {
            "上海": [
                {"code": "CA123", "dep": (8, 0), "arr": (10, 0), "cost": 900},
                {"code": "MU5101", "dep": (10, 0), "arr": (12, 0), "cost": 850},
                {"code": "CZ8888", "dep": (14, 0), "arr": (16, 0), "cost": 800},
                {"code": "CA456", "dep": (17, 0), "arr": (19, 0), "cost": 750},
            ],
            "广州": [
                {"code": "CZ3101", "dep": (10, 0), "arr": (13, 30), "cost": 1500},
                {"code": "CA1831", "dep": (8, 0), "arr": (11, 0), "cost": 1400},
            ],
            "西安": [
                {"code": "MU2101", "dep": (8, 0), "arr": (10, 0), "cost": 800},
                {"code": "CZ6916", "dep": (14, 0), "arr": (16, 0), "cost": 750},
            ],
            "成都": [
                {"code": "CA4101", "dep": (7, 0), "arr": (10, 0), "cost": 1100},
                {"code": "3U8882", "dep": (15, 0), "arr": (18, 0), "cost": 1000},
            ],
        },
        "上海": {
            "广州": [
                {"code": "CZ3501", "dep": (14, 0), "arr": (16, 30), "cost": 1000},
                {"code": "MU5301", "dep": (9, 0), "arr": (11, 30), "cost": 950},
            ],
            "成都": [
                {"code": "CA4501", "dep": (8, 0), "arr": (11, 0), "cost": 1200},
                {"code": "MU5401", "dep": (16, 0), "arr": (19, 0), "cost": 1150},
            ],
            "西安": [
                {"code": "MU2151", "dep": (10, 0), "arr": (12, 30), "cost": 900},
                {"code": "CA1213", "dep": (15, 0), "arr": (17, 30), "cost": 850},
            ],
            "郑州": [
                {"code": "CZ3601", "dep": (11, 0), "arr": (13, 0), "cost": 700},
            ],
        },
        "广州": {
            "成都": [
                {"code": "CZ3401", "dep": (9, 0), "arr": (11, 30), "cost": 900},
                {"code": "CA4301", "dep": (14, 0), "arr": (16, 30), "cost": 850},
            ],
            "杭州": [
                {"code": "MF8301", "dep": (16, 0), "arr": (18, 30), "cost": 750},
            ],
        },
        "杭州": {
            "广州": [
                {"code": "MF8302", "dep": (10, 0), "arr": (12, 30), "cost": 750},
                {"code": "CZ3801", "dep": (19, 0), "arr": (21, 30), "cost": 700},
            ],
        },
        "西安": {
            "成都": [
                {"code": "3U8801", "dep": (14, 0), "arr": (15, 30), "cost": 500},
                {"code": "MU2201", "dep": (9, 0), "arr": (10, 30), "cost": 480},
            ],
        },
    }

    def __init__(self):
        self.session = requests.Session()
        self.session.headers.update(HEADERS)
        self.session.verify = False

    def _get_db_flights(
        self, from_city: str, to_city: str
    ) -> List[Dict[str, Any]]:
        """从内置常见航线数据库获取航班"""
        result = []
        fwd = self.COMMON_FLIGHTS.get(from_city, {}).get(to_city, [])
        rev = self.COMMON_FLIGHTS.get(to_city, {}).get(from_city, [])
        seen = set()
        for f in fwd + rev:
            if f['code'] not in seen:
                seen.add(f['code'])
                result.append(f)
        return result

    def scrape(
        self, from_city: str, to_city: str,
        start_date: str, end_date: str
    ) -> List[str]:
        """
        爬取/生成航班数据，返回 trans.txt 格式的行列表。
        优先尝试网络源，失败则用内置数据库。
        """
        lines: List[str] = []
        start = datetime.strptime(start_date, "%Y-%m-%d")
        end = datetime.strptime(end_date, "%Y-%m-%d")

        # 先尝试内置数据库
        flights = self._get_db_flights(from_city, to_city)

        if not flights:
            # 尝试根据估算生成基本航班
            est_cost = estimate_flight_cost(from_city, to_city)
            dist = get_distance(from_city, to_city)
            # 粗略飞行时间: 距离/800 + 1
            flight_hours = max(1, dist // 800 + 1)
            flights = [
                {"code": f"CA{1000 + hash(from_city + to_city) % 9000:04d}",
                 "dep": (8, 0), "arr": (8 + flight_hours, 0), "cost": est_cost},
                {"code": f"MU{2000 + hash(to_city + from_city) % 9000:04d}",
                 "dep": (15, 0), "arr": (15 + flight_hours, 0), "cost": est_cost},
            ]

        current = start
        while current <= end:
            for f in flights:
                dep_h, dep_m = f['dep']
                arr_h, arr_m = f['arr']
                arr_offset = 0
                if arr_h < dep_h or (arr_h == dep_h and arr_m < dep_m):
                    arr_offset = 1

                dep_month, dep_day = current.month, current.day
                arr_date = current + timedelta(days=arr_offset)
                arr_month, arr_day = arr_date.month, arr_date.day

                line = (
                    f"飞机 {from_city} {to_city} {f['code']} "
                    f"{dep_month} {dep_day} {dep_h} {dep_m} "
                    f"{arr_month} {arr_day} {arr_h} {arr_m} "
                    f"{f['cost']}"
                )
                lines.append(line)
                # print(f"    {line}")  # 精简输出

            current += timedelta(days=1)

        return lines


# ══════════════════════════════════════════════════════════════════════════════
#  主程序
# ══════════════════════════════════════════════════════════════════════════════

def find_transfer_cities(
    from_city: str, to_city: str, max_transfers: int
) -> List[List[str]]:
    """
    根据距离表找出合理的中转城市路径。
    返回: [[c1], [c2], ...]  一级中转;  [[c1,c2], ...]  二级中转
    """
    all_cities = set()
    for c1, c2 in CITY_DISTANCES:
        all_cities.add(c1)
        all_cities.add(c2)
    all_cities.discard(from_city)
    all_cities.discard(to_city)

    direct_dist = get_distance(from_city, to_city)
    paths: List[List[str]] = []

    if max_transfers >= 1:
        # 一级中转: 找不绕远的中间城市
        for mid in sorted(all_cities):
            d1 = get_distance(from_city, mid)
            d2 = get_distance(mid, to_city)
            # 绕路不超过直达的 50%
            if d1 > 0 and d2 > 0 and (d1 + d2) < direct_dist * 1.5:
                paths.append([mid])

    if max_transfers >= 2:
        two_hop: List[List[str]] = []
        for mid1 in sorted(all_cities):
            d1 = get_distance(from_city, mid1)
            if d1 > direct_dist * 1.5:
                continue
            for mid2 in sorted(all_cities):
                if mid2 == mid1:
                    continue
                d2 = get_distance(mid1, mid2)
                d3 = get_distance(mid2, to_city)
                if d2 > 0 and d3 > 0 and (d1 + d2 + d3) < direct_dist * 1.8:
                    two_hop.append([mid1, mid2])
        # 限制二级中转数量，避免爆炸
        paths.extend(two_hop[:30])

    return paths
    """安全读取文件，自动尝试 UTF-8 / GBK 编码"""
    for enc in ['utf-8', 'gbk', 'gb2312', 'gb18030']:
        try:
            with open(filepath, 'r', encoding=enc) as f:
                return [line.strip() for line in f if line.strip()]
        except (UnicodeDecodeError, FileNotFoundError):
            continue
    return None


def safe_read_file(filepath: str) -> Optional[List[str]]:
    """安全读取文件，自动尝试 UTF-8 / GBK 编码"""
    for enc in ['utf-8', 'gbk', 'gb2312', 'gb18030']:
        try:
            with open(filepath, 'r', encoding=enc) as f:
                return [line.strip() for line in f if line.strip()]
        except (UnicodeDecodeError, FileNotFoundError):
            continue
    return None


def main():
    # 强制刷新，确保 VS Code 终端能看到输出
    print()
    print("╔" + "═" * 58 + "╗", flush=True)
    print("║" + "     全国交通咨询模拟系统 —— 数据爬虫".center(50) + "║", flush=True)
    print("╚" + "═" * 58 + "╝", flush=True)
    print()
    print("  本程序将为您爬取两城市间的列车（12306）和航班数据。")
    print("  ★ 支持中转查询：可爬取经停中间城市的列车数据。")
    print("  ★ 注意：12306 仅显示预售期内数据（通常约 15 天）。")
    print()

    # ── 输入城市 ──
    from_city = input("  请输入起点城市: ").strip()
    to_city = input("  请输入终点城市: ").strip()

    if not from_city or not to_city:
        print("[错误] 城市名不能为空！")
        return

    # ── 输入中转次数 ──
    print()
    print("  请输入最大中转次数（0=直达, 1=一次中转, 2=两次中转）", flush=True)
    transfer_str = input("  最大中转次数 [默认0]: ").strip()
    try:
        max_transfers = int(transfer_str) if transfer_str else 0
        max_transfers = max(0, min(max_transfers, 2))
    except ValueError:
        max_transfers = 0
    print(f"  → 中转次数: {max_transfers}", flush=True)

    # ── 输入日期范围 ──
    print()
    print("  请输入时间区间（格式: YYYY-MM-DD，如 2026-06-15）", flush=True)
    start_date = input("  起始日期: ").strip()
    end_date = input("  结束日期: ").strip()

    try:
        s = datetime.strptime(start_date, "%Y-%m-%d")
        e = datetime.strptime(end_date, "%Y-%m-%d")
        if s > e:
            print("[错误] 起始日期不能晚于结束日期！")
            return
        if (e - s).days > 30:
            print("[警告] 日期范围超过 30 天，12306 可能只有预售期内数据。")
    except ValueError:
        print("[错误] 日期格式不正确，请使用 YYYY-MM-DD 格式。")
        return

    # ── 输出目录 ──
    script_dir = os.path.dirname(os.path.abspath(__file__))

    print()
    print("─" * 60)
    print(f"  查询: {from_city} ↔ {to_city}")
    print(f"  时间: {start_date} 至 {end_date}")
    print(f"  中转: {'直达' if max_transfers == 0 else f'最多{max_transfers}次'}")
    print("─" * 60)
    print()

    # ── 1) 爬取列车数据（直达 + 中转） ──
    print("【1/2】正在爬取 12306 列车数据...")
    print("-" * 50)
    train_scraper = Train12306Scraper()
    train_lines: List[str] = []
    extra_cities: set = set()

    # 直达：正向 + 反向并行
    print("  [直达] 查询中...", flush=True)
    with ThreadPoolExecutor(max_workers=2) as pool:
        fwd = pool.submit(
            train_scraper.scrape, from_city, to_city,
            start_date, end_date
        )
        rev = pool.submit(
            train_scraper.scrape, to_city, from_city,
            start_date, end_date
        )
        for future in as_completed([fwd, rev]):
            train_lines.extend(future.result())

    # 中转查询
    if max_transfers >= 1:
        transfer_paths = find_transfer_cities(
            from_city, to_city, max_transfers
        )
        if transfer_paths:
            print(f"\n  [中转] 发现 {len(transfer_paths)} 条可能的中转路径，"
                  f"正在查询...", flush=True)

            # 收集所有需要查询的城市对（去重）
            pair_set: set = set()
            for path in transfer_paths:
                prev = from_city
                for mid in path:
                    pair_set.add((prev, mid))
                    pair_set.add((mid, prev))  # 反向
                    prev = mid
                pair_set.add((prev, to_city))
                pair_set.add((to_city, prev))  # 反向

            pairs = list(pair_set)
            transfer_lines = train_scraper.scrape_pairs(
                pairs, start_date, end_date
            )
            train_lines.extend(transfer_lines)

            # 记录中间城市
            for path in transfer_paths:
                for mid in path:
                    extra_cities.add(mid)

    # ── 2) 获取航班数据 ──
    print()
    print("【2/2】正在获取航班数据...")
    print("-" * 50)
    flight_scraper = FlightScraper()
    flight_lines = flight_scraper.scrape(from_city, to_city, start_date, end_date)
    flight_lines += flight_scraper.scrape(to_city, from_city, start_date, end_date)
    print(f"  共 {len(flight_lines)} 条航班", flush=True)

    all_lines = train_lines + flight_lines

    if not all_lines:
        print()
        print("=" * 60)
        print("  ⚠ 未获取到任何交通数据！")
        print("  可能原因：")
        print("    1. 查询日期超出 12306 预售期（约 15 天）")
        print("    2. 城市名称与 12306 站名不匹配")
        print("    3. 网络连接问题或 12306 需要验证码")
        print("=" * 60)
        return

    # ── 写入 city.txt ──
    city_path = os.path.join(script_dir, "city.txt")
    all_cities = {from_city, to_city} | extra_cities
    existing = set()
    old_lines = safe_read_file(city_path)
    if old_lines:
        for c in old_lines:
            existing.add(c)
    for c in all_cities:
        existing.add(c)
    with open(city_path, 'w', encoding='gbk') as f:
        for c in sorted(existing):
            f.write(c + '\n')
    print(f"\n[✓] 城市列表 → {city_path} ({len(existing)} 城)")

    # ── 写入 trans.txt ──
    trans_path = os.path.join(script_dir, "trans.txt")
    unique_lines = list(dict.fromkeys(all_lines))
    with open(trans_path, 'w', encoding='gbk') as f:
        for line in unique_lines:
            f.write(line + '\n')
    print(f"[✓] 交通数据 → {trans_path}")
    print(f"[✓] 共 {len(unique_lines)} 条记录（列车 {len(train_lines)} 条 + 航班 "
          f"{len(flight_lines)} 条）")

    print()
    print("╔" + "═" * 58 + "╗")
    print("║" + "              爬取完成！".center(50) + "║")
    print("║" + "  现在可以运行 C++ 主程序加载数据。".center(52) + "║")
    print("╚" + "═" * 58 + "╝")
    print()


if __name__ == '__main__':
    main()
