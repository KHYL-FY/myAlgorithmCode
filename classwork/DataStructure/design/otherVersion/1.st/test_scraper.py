#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""测试爬虫输出格式"""
import sys
import re

exec(open('1.py', encoding='utf-8').read().replace("if __name__ == '__main__':", "if False:"))

print('=== 测试完整爬取流程 ===')
train_scraper = Train12306Scraper()
train_lines = train_scraper.scrape('北京', '上海', '2026-06-16', '2026-06-16')
print(f'列车行数: {len(train_lines)}')

rev_lines = train_scraper.scrape('上海', '北京', '2026-06-16', '2026-06-16')
print(f'反向列车行数: {len(rev_lines)}')

flight_scraper = FlightScraper()
flight_lines = flight_scraper.scrape('北京', '上海', '2026-06-16', '2026-06-16')
print(f'航班行数: {len(flight_lines)}')

all_lines = train_lines + rev_lines + flight_lines

print()
print('=== 前 5 行输出 ===')
for line in all_lines[:5]:
    print(line)

print()
print('=== 格式验证 ===')
pattern = r'^(火车|飞机) \S+ \S+ \S+ \d+ \d+ \d+ \d+ \d+ \d+ \d+ \d+ \d+$'
ok = 0
fail = 0
for i, line in enumerate(all_lines[:20]):
    if re.match(pattern, line):
        ok += 1
    else:
        fail += 1
        print(f'  FAIL[{i}]: {line}')
print(f'通过: {ok}, 失败: {fail}')

# 写入测试输出
with open('trans_test.txt', 'w', encoding='utf-8') as f:
    for line in all_lines[:10]:
        f.write(line + '\n')
print('\n已写入 trans_test.txt')
