#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// ==================== 时间工具函数 ====================

// 将时间字符串（如 "08:30"）转换为分钟数
int timeToMinutes(const string &timeStr)
{
    int hour, minute;
    char colon;
    stringstream ss(timeStr);
    ss >> hour >> colon >> minute;
    return hour * 60 + minute;
}

// 将分钟数转换为时间字符串
string minutesToTime(int minutes)
{
    int hour = minutes / 60;
    int minute = minutes % 60;
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":"
       << setw(2) << setfill('0') << minute;
    return ss.str();
}

// 计算两个时间之间的分钟差
int timeDiff(const string &start, const string &end)
{
    return timeToMinutes(end) - timeToMinutes(start);
}

// ==================== 数据结构定义 ====================

// 交通工具类型
enum TransportType
{
    TRAIN,
    PLANE
};

// 边（交通连接）的信息
struct Edge
{
    int targetCity;        // 目标城市编号
    TransportType type;    // 交通工具类型
    string scheduleId;     // 车次/航班号
    double cost;           // 票价
    int duration;          // 运行时间（分钟）
    int departureTime;     // 出发时间（分钟数）
    int arrivalTime;       // 到达时间（分钟数）
    string weeklySchedule; // 班期（飞机用，如 "1234567"）

    Edge() {}
    Edge(int target, TransportType t, const string &id, double c,
         int dep, int arr, const string &schedule = "1234567")
        : targetCity(target), type(t), scheduleId(id), cost(c),
          departureTime(dep), arrivalTime(arr), weeklySchedule(schedule)
    {
        duration = arrivalTime - departureTime;
        if (duration < 0)
            duration += 24 * 60; // 跨午夜的情况
    }

    // 检查某天是否有班期（飞机用）
    bool isAvailableOnWeekday(int weekday) const
    {
        // weekday: 1=周一, 7=周日
        char target = '0' + weekday;
        return weeklySchedule.find(target) != string::npos;
    }
};

// 城市信息
struct City
{
    int id;
    string name;

    City() : id(-1) {}
    City(int i, const string &n) : id(i), name(n) {}
};

// 路径节点（用于Dijkstra算法）
struct PathNode
{
    int city;
    int arriveTime;   // 到达该城市的时间
    double totalCost; // 累计费用
    int transfers;    // 中转次数
    int prevCity;     // 前驱城市
    int edgeIndex;    // 使用的边索引

    PathNode() : city(-1), arriveTime(0), totalCost(0), transfers(0),
                 prevCity(-1), edgeIndex(-1) {}

    PathNode(int c, int time, double cost, int trans, int prev, int edge)
        : city(c), arriveTime(time), totalCost(cost), transfers(trans),
          prevCity(prev), edgeIndex(edge) {}

    // 用于优先队列（时间优先）
    bool operator>(const PathNode &other) const
    {
        return arriveTime > other.arriveTime;
    }
};

// 用于费用优先的比较
struct CostNode
{
    int city;
    double totalCost;
    int arriveTime;
    int prevCity;
    int edgeIndex;

    CostNode() : city(-1), totalCost(0), arriveTime(0), prevCity(-1), edgeIndex(-1) {}
    CostNode(int c, double cost, int time, int prev, int edge)
        : city(c), totalCost(cost), arriveTime(time), prevCity(prev), edgeIndex(edge) {}

    bool operator>(const CostNode &other) const
    {
        return totalCost > other.totalCost;
    }
};

// 用于中转次数优先的比较
struct TransferNode
{
    int city;
    int transfers;
    int arriveTime;
    int prevCity;
    int edgeIndex;

    TransferNode() : city(-1), transfers(0), arriveTime(0), prevCity(-1), edgeIndex(-1) {}
    TransferNode(int c, int trans, int time, int prev, int edge)
        : city(c), transfers(trans), arriveTime(time), prevCity(prev), edgeIndex(edge) {}

    bool operator>(const TransferNode &other) const
    {
        return transfers > other.transfers;
    }
};

// ==================== 交通咨询系统类 ====================

class TrafficSystem
{
private:
    vector<City> cities;           // 城市列表
    map<string, int> cityNameToId; // 城市名到ID的映射
    vector<vector<Edge>> graph;    // 邻接表

    // 辅助函数：查找城市ID
    int findCityId(const string &cityName)
    {
        auto it = cityNameToId.find(cityName);
        if (it != cityNameToId.end())
        {
            return it->second;
        }
        return -1;
    }

    // 辅助函数：获取当前日期（模拟，返回星期几 1-7）
    int getCurrentWeekday()
    {
        // 简化为周一，实际可以系统时间或用户输入
        return 1;
    }

    // 计算等待时间
    int calculateWaitTime(int arriveTime, int departureTime)
    {
        if (departureTime >= arriveTime)
        {
            return departureTime - arriveTime;
        }
        else
        {
            // 跨天的情况
            return (24 * 60 - arriveTime) + departureTime;
        }
    }

    // 计算实际出发时间（考虑到达时间后的第一班可用班次）
    int getActualDepartureTime(int arriveTime, const Edge &edge, int weekday)
    {
        // 对于火车，通常每天都有多班，这里简化为找到当天第一班
        // 实际系统应该根据时刻表查找
        if (edge.departureTime >= arriveTime)
        {
            return edge.departureTime;
        }
        else
        {
            // 需要等到第二天
            return edge.departureTime;
        }
    }

    // 打印路径（时间优先）
    void printPath(const vector<PathNode> &nodes, int targetCity,
                   const vector<Edge> &edges, int startCity)
    {
        if (targetCity == startCity)
        {
            return;
        }

        vector<pair<int, int>> path; // (city, edgeIndex)
        int curr = targetCity;
        while (curr != startCity)
        {
            path.push_back({curr, nodes[curr].edgeIndex});
            curr = nodes[curr].prevCity;
        }

        // 反向输出
        cout << endl
             << "=== 详细路线 ===" << endl;
        int currentTime = -1;
        double totalCost = 0;

        for (int i = path.size() - 1; i >= 0; i--)
        {
            int cityId = path[i].first;
            int edgeIdx = path[i].second;
            const Edge &e = edges[edgeIdx];
            const City &fromCity = cities[e.targetCity == cityId ? nodes[cityId].prevCity : e.targetCity];
            const City &toCity = cities[cityId];

            string transportName = (e.type == TRAIN) ? "列车" : "航班";
            string scheduleId = e.scheduleId;

            cout << (i == (int)path.size() - 1 ? "1. " : "   ")
                 << "在" << fromCity.name << "乘坐 " << transportName
                 << " " << scheduleId << "，"
                 << minutesToTime(e.departureTime) << " 出发，"
                 << minutesToTime(e.arrivalTime) << " 到达" << toCity.name << endl;

            if (i > 0)
            {
                // 计算等待时间
                int waitTime = calculateWaitTime(e.arrivalTime,
                                                 edges[path[i - 1].second].departureTime);
                if (waitTime > 0)
                {
                    cout << "   等待时间：" << waitTime / 60 << "小时"
                         << waitTime % 60 << "分钟" << endl;
                }
            }

            totalCost += e.cost;
        }

        cout << endl
             << "总票价：" << totalCost << "元" << endl;
        cout << "总耗时：" << nodes[targetCity].arriveTime / 60 << "小时"
             << nodes[targetCity].arriveTime % 60 << "分钟" << endl;
    }

    // 打印路径（费用优先）
    void printCostPath(const vector<CostNode> &nodes, int targetCity,
                       const vector<Edge> &edges, int startCity)
    {
        if (targetCity == startCity)
            return;

        vector<pair<int, int>> path;
        int curr = targetCity;
        while (curr != startCity)
        {
            path.push_back({curr, nodes[curr].edgeIndex});
            curr = nodes[curr].prevCity;
        }

        cout << endl
             << "=== 详细路线 ===" << endl;
        double totalCost = 0;

        for (int i = path.size() - 1; i >= 0; i--)
        {
            int cityId = path[i].first;
            int edgeIdx = path[i].second;
            const Edge &e = edges[edgeIdx];
            const City &fromCity = cities[e.targetCity == cityId ? nodes[cityId].prevCity : e.targetCity];
            const City &toCity = cities[cityId];

            string transportName = (e.type == TRAIN) ? "列车" : "航班";
            cout << (i == (int)path.size() - 1 ? "1. " : "   ")
                 << "从" << fromCity.name << "乘坐 " << transportName
                 << " " << e.scheduleId << "，"
                 << minutesToTime(e.departureTime) << " 出发，"
                 << minutesToTime(e.arrivalTime) << " 到达" << toCity.name << endl;

            totalCost += e.cost;
        }

        cout << endl
             << "总票价：" << totalCost << "元" << endl;
    }

public:
    TrafficSystem()
    {
        loadData();
    }

    // ==================== 数据加载与保存 ====================

    void loadData()
    {
        // 加载城市
        ifstream cityFile("cities.txt");
        if (cityFile.is_open())
        {
            string line;
            while (getline(cityFile, line))
            {
                size_t pos = line.find('|');
                if (pos != string::npos)
                {
                    int id = stoi(line.substr(0, pos));
                    string name = line.substr(pos + 1);
                    cities.push_back(City(id, name));
                    cityNameToId[name] = id;
                }
            }
            cityFile.close();
            cout << "加载了 " << cities.size() << " 个城市" << endl;
        }
        else
        {
            // 初始化默认城市
            cout << "未找到城市文件，初始化默认城市..." << endl;
            initDefaultCities();
        }

        // 初始化图
        graph.resize(cities.size());

        // 加载列车时刻表
        loadTrains();

        // 加载飞机航班
        loadFlights();
    }

    void initDefaultCities()
    {
        vector<pair<int, string>> defaultCities = {
            {0, "北京"}, {1, "上海"}, {2, "广州"}, {3, "深圳"}, {4, "成都"}, {5, "武汉"}, {6, "西安"}, {7, "杭州"}};
        for (const auto &c : defaultCities)
        {
            cities.push_back(City(c.first, c.second));
            cityNameToId[c.second] = c.first;
        }
    }

    void loadTrains()
    {
        ifstream trainFile("trains.txt");
        if (trainFile.is_open())
        {
            string line;
            while (getline(trainFile, line))
            {
                // 格式: 车次|起点|终点|出发时间|到达时间|票价
                vector<string> parts;
                size_t pos = 0;
                while ((pos = line.find('|')) != string::npos)
                {
                    parts.push_back(line.substr(0, pos));
                    line.erase(0, pos + 1);
                }
                parts.push_back(line);

                if (parts.size() >= 6)
                {
                    string scheduleId = parts[0];
                    string fromCity = parts[1];
                    string toCity = parts[2];
                    string depTime = parts[3];
                    string arrTime = parts[4];
                    double cost = stod(parts[5]);

                    int fromId = findCityId(fromCity);
                    int toId = findCityId(toCity);

                    if (fromId != -1 && toId != -1)
                    {
                        Edge edge(toId, TRAIN, scheduleId, cost,
                                  timeToMinutes(depTime), timeToMinutes(arrTime));
                        graph[fromId].push_back(edge);
                    }
                }
            }
            trainFile.close();
            cout << "加载了列车时刻表" << endl;
        }
        else
        {
            // 创建默认列车数据
            createDefaultTrains();
        }
    }

    void createDefaultTrains()
    {
        cout << "创建默认列车数据..." << endl;
        vector<tuple<string, string, string, string, string, double>> defaultTrains = {
            {"G1", "北京", "上海", "08:00", "12:00", 550},
            {"G2", "上海", "北京", "14:00", "18:00", 550},
            {"G3", "北京", "广州", "09:00", "18:00", 860},
            {"G4", "广州", "北京", "10:00", "19:00", 860},
            {"G5", "上海", "广州", "08:30", "13:30", 620},
            {"G6", "广州", "上海", "15:00", "20:00", 620},
            {"G7", "北京", "武汉", "07:30", "11:30", 520},
            {"G8", "武汉", "北京", "16:00", "20:00", 520},
            {"G9", "上海", "杭州", "09:00", "10:30", 150},
            {"G10", "杭州", "上海", "18:00", "19:30", 150},
            {"G11", "北京", "西安", "10:00", "14:30", 620},
            {"G12", "西安", "北京", "15:00", "19:30", 620},
            {"G13", "成都", "西安", "08:00", "12:00", 350},
            {"G14", "西安", "成都", "13:00", "17:00", 350},
            {"K1", "武汉", "广州", "20:00", "06:00", 480}, // 夜车
            {"K2", "广州", "武汉", "21:00", "07:00", 480}};

        for (const auto &train : defaultTrains)
        {
            string sid = get<0>(train);
            string from = get<1>(train);
            string to = get<2>(train);
            string dep = get<3>(train);
            string arr = get<4>(train);
            double cost = get<5>(train);

            int fromId = findCityId(from);
            int toId = findCityId(to);

            if (fromId != -1 && toId != -1)
            {
                Edge edge(toId, TRAIN, sid, cost,
                          timeToMinutes(dep), timeToMinutes(arr));
                graph[fromId].push_back(edge);
            }
        }
    }

    void loadFlights()
    {
        ifstream flightFile("flights.txt");
        if (flightFile.is_open())
        {
            string line;
            while (getline(flightFile, line))
            {
                // 格式: 航班号|起点|终点|班期|起飞时间|到达时间|机型|票价
                vector<string> parts;
                size_t pos = 0;
                while ((pos = line.find('|')) != string::npos)
                {
                    parts.push_back(line.substr(0, pos));
                    line.erase(0, pos + 1);
                }
                parts.push_back(line);

                if (parts.size() >= 8)
                {
                    string scheduleId = parts[0];
                    string fromCity = parts[1];
                    string toCity = parts[2];
                    string weekly = parts[3];
                    string depTime = parts[4];
                    string arrTime = parts[5];
                    double cost = stod(parts[7]);

                    int fromId = findCityId(fromCity);
                    int toId = findCityId(toCity);

                    if (fromId != -1 && toId != -1)
                    {
                        Edge edge(toId, PLANE, scheduleId, cost,
                                  timeToMinutes(depTime), timeToMinutes(arrTime), weekly);
                        graph[fromId].push_back(edge);
                    }
                }
            }
            flightFile.close();
            cout << "加载了飞机航班表" << endl;
        }
        else
        {
            // 创建默认航班数据
            createDefaultFlights();
        }
    }

    void createDefaultFlights()
    {
        cout << "创建默认航班数据..." << endl;
        vector<tuple<string, string, string, string, string, string, double>> defaultFlights = {
            {"CA1234", "北京", "上海", "1234567", "09:00", "11:00", 800},
            {"CA1235", "上海", "北京", "1234567", "15:00", "17:00", 800},
            {"CZ3521", "北京", "广州", "1234567", "10:00", "13:30", 1200},
            {"CZ3522", "广州", "北京", "1234567", "14:30", "17:30", 1200},
            {"MU5321", "上海", "广州", "1234567", "11:00", "13:30", 950},
            {"MU5322", "广州", "上海", "1234567", "16:00", "18:30", 950},
            {"CA1678", "北京", "成都", "1234567", "08:00", "11:00", 980},
            {"CA1679", "成都", "北京", "1234567", "12:00", "15:00", 980},
            {"3U8881", "成都", "西安", "1234567", "09:30", "10:30", 350},
            {"3U8882", "西安", "成都", "1234567", "11:30", "12:30", 350}};

        for (const auto &flight : defaultFlights)
        {
            string fid = get<0>(flight);
            string from = get<1>(flight);
            string to = get<2>(flight);
            string weekly = get<3>(flight);
            string dep = get<4>(flight);
            string arr = get<5>(flight);
            double cost = get<6>(flight);

            int fromId = findCityId(from);
            int toId = findCityId(to);

            if (fromId != -1 && toId != -1)
            {
                Edge edge(toId, PLANE, fid, cost,
                          timeToMinutes(dep), timeToMinutes(arr), weekly);
                graph[fromId].push_back(edge);
            }
        }
    }

    void saveData()
    {
        // 保存城市
        ofstream cityFile("cities.txt");
        if (cityFile.is_open())
        {
            for (const auto &city : cities)
            {
                cityFile << city.id << "|" << city.name << endl;
            }
            cityFile.close();
        }

        // 保存列车时刻表
        ofstream trainFile("trains.txt");
        if (trainFile.is_open())
        {
            // 从图中收集列车信息
            set<string> saved;
            for (size_t i = 0; i < graph.size(); i++)
            {
                for (const auto &edge : graph[i])
                {
                    if (edge.type == TRAIN)
                    {
                        string key = edge.scheduleId + "|" + to_string(i);
                        if (saved.find(key) == saved.end())
                        {
                            trainFile << edge.scheduleId << "|"
                                      << cities[i].name << "|"
                                      << cities[edge.targetCity].name << "|"
                                      << minutesToTime(edge.departureTime) << "|"
                                      << minutesToTime(edge.arrivalTime) << "|"
                                      << edge.cost << endl;
                            saved.insert(key);
                        }
                    }
                }
            }
            trainFile.close();
        }

        // 保存航班
        ofstream flightFile("flights.txt");
        if (flightFile.is_open())
        {
            set<string> saved;
            for (size_t i = 0; i < graph.size(); i++)
            {
                for (const auto &edge : graph[i])
                {
                    if (edge.type == PLANE)
                    {
                        string key = edge.scheduleId + "|" + to_string(i);
                        if (saved.find(key) == saved.end())
                        {
                            flightFile << edge.scheduleId << "|"
                                       << cities[i].name << "|"
                                       << cities[edge.targetCity].name << "|"
                                       << edge.weeklySchedule << "|"
                                       << minutesToTime(edge.departureTime) << "|"
                                       << minutesToTime(edge.arrivalTime) << "|"
                                       << "A320|" << edge.cost << endl;
                            saved.insert(key);
                        }
                    }
                }
            }
            flightFile.close();
        }

        cout << "数据已保存！" << endl;
    }

    // ==================== 城市管理 ====================

    void addCity()
    {
        string cityName;
        cout << "请输入城市名称: ";
        cin.ignore();
        getline(cin, cityName);

        if (findCityId(cityName) != -1)
        {
            cout << "城市已存在！" << endl;
            return;
        }

        int newId = cities.size();
        cities.push_back(City(newId, cityName));
        cityNameToId[cityName] = newId;
        graph.resize(cities.size());
        cout << "成功添加城市：" << cityName << endl;
    }

    void deleteCity()
    {
        string cityName;
        cout << "请输入要删除的城市名称: ";
        cin.ignore();
        getline(cin, cityName);

        int cityId = findCityId(cityName);
        if (cityId == -1)
        {
            cout << "城市不存在！" << endl;
            return;
        }

        // 删除城市相关的所有边
        for (auto &edges : graph)
        {
            edges.erase(remove_if(edges.begin(), edges.end(),
                                  [cityId](const Edge &e)
                                  { return e.targetCity == cityId; }),
                        edges.end());
        }
        graph.erase(graph.begin() + cityId);

        // 更新后续城市的ID
        for (int i = cityId + 1; i < (int)cities.size(); i++)
        {
            string name = cities[i].name;
            cityNameToId[name] = i - 1;
        }

        cities.erase(cities.begin() + cityId);
        cityNameToId.erase(cityName);

        // 更新所有边中的targetCity
        for (auto &edges : graph)
        {
            for (auto &edge : edges)
            {
                if (edge.targetCity > cityId)
                {
                    edge.targetCity--;
                }
            }
        }

        cout << "成功删除城市：" << cityName << endl;
    }

    void listCities()
    {
        cout << "\n=== 城市列表 ===" << endl;
        for (const auto &city : cities)
        {
            cout << city.id << ". " << city.name << endl;
        }
    }

    // ==================== 交通数据管理 ====================

    void addSchedule()
    {
        cout << "请选择交通工具：1.火车  2.飞机" << endl;
        int type;
        cin >> type;

        if (type == 1)
        {
            string scheduleId, fromCity, toCity, depTime, arrTime;
            double cost;

            cout << "请输入车次: ";
            cin >> scheduleId;
            cout << "请输入起点城市: ";
            cin >> fromCity;
            cout << "请输入终点城市: ";
            cin >> toCity;
            cout << "请输入出发时间 (HH:MM): ";
            cin >> depTime;
            cout << "请输入到达时间 (HH:MM): ";
            cin >> arrTime;
            cout << "请输入票价: ";
            cin >> cost;

            int fromId = findCityId(fromCity);
            int toId = findCityId(toCity);

            if (fromId == -1 || toId == -1)
            {
                cout << "城市不存在！" << endl;
                return;
            }

            Edge edge(toId, TRAIN, scheduleId, cost,
                      timeToMinutes(depTime), timeToMinutes(arrTime));
            graph[fromId].push_back(edge);
            cout << "成功添加列车时刻！" << endl;
        }
        else if (type == 2)
        {
            string flightId, fromCity, toCity, weekly, depTime, arrTime;
            double cost;

            cout << "请输入航班号: ";
            cin >> flightId;
            cout << "请输入起点城市: ";
            cin >> fromCity;
            cout << "请输入终点城市: ";
            cin >> toCity;
            cout << "请输入班期 (1-7数字，如 1234567 表示每天): ";
            cin >> weekly;
            cout << "请输入起飞时间 (HH:MM): ";
            cin >> depTime;
            cout << "请输入到达时间 (HH:MM): ";
            cin >> arrTime;
            cout << "请输入票价: ";
            cin >> cost;

            int fromId = findCityId(fromCity);
            int toId = findCityId(toCity);

            if (fromId == -1 || toId == -1)
            {
                cout << "城市不存在！" << endl;
                return;
            }

            Edge edge(toId, PLANE, flightId, cost,
                      timeToMinutes(depTime), timeToMinutes(arrTime), weekly);
            graph[fromId].push_back(edge);
            cout << "成功添加航班！" << endl;
        }
    }

    void deleteSchedule()
    {
        cout << "请选择交通工具：1.火车  2.飞机" << endl;
        int type;
        cin >> type;

        string scheduleId;
        cout << "请输入要删除的车次/航班号: ";
        cin >> scheduleId;

        bool found = false;
        for (auto &edges : graph)
        {
            edges.erase(remove_if(edges.begin(), edges.end(),
                                  [type, scheduleId, &found](const Edge &e)
                                  {
                                      if (e.type == (type == 1 ? TRAIN : PLANE) && e.scheduleId == scheduleId)
                                      {
                                          found = true;
                                          return true;
                                      }
                                      return false;
                                  }),
                        edges.end());
        }

        if (found)
        {
            cout << "成功删除！" << endl;
        }
        else
        {
            cout << "未找到该" << (type == 1 ? "车次" : "航班") << "！" << endl;
        }
    }

    // ==================== 路径查询 ====================

    // 最快到达（时间优先，考虑等待时间）
    void fastestPath(int start, int target, TransportType type)
    {
        const int INF = INT_MAX;
        vector<PathNode> best(cities.size());
        vector<bool> visited(cities.size(), false);

        for (size_t i = 0; i < cities.size(); i++)
        {
            best[i].arriveTime = INF;
            best[i].totalCost = INF;
        }

        best[start].arriveTime = 0;
        best[start].city = start;
        best[start].prevCity = -1;

        priority_queue<PathNode, vector<PathNode>, greater<PathNode>> pq;
        pq.push(PathNode(start, 0, 0, 0, -1, -1));

        while (!pq.empty())
        {
            PathNode current = pq.top();
            pq.pop();

            if (visited[current.city])
                continue;
            visited[current.city] = true;

            if (current.city == target)
                break;

            for (const Edge &edge : graph[current.city])
            {
                if (edge.type != type)
                    continue;

                // 计算实际出发时间（考虑等待）
                int actualDep = current.arriveTime;
                if (edge.departureTime < current.arriveTime % (24 * 60))
                {
                    // 需要等到第二天
                    actualDep = current.arriveTime +
                                (24 * 60 - current.arriveTime % (24 * 60)) +
                                edge.departureTime;
                }
                else
                {
                    actualDep = current.arriveTime - (current.arriveTime % (24 * 60)) +
                                edge.departureTime;
                }

                int waitTime = actualDep - current.arriveTime;
                int arrival = actualDep + edge.duration;

                if (arrival < best[edge.targetCity].arriveTime)
                {
                    best[edge.targetCity].arriveTime = arrival;
                    best[edge.targetCity].prevCity = current.city;
                    best[edge.targetCity].edgeIndex = edge.targetCity;
                    best[edge.targetCity].totalCost = current.totalCost + edge.cost;
                    pq.push(PathNode(edge.targetCity, arrival,
                                     current.totalCost + edge.cost, 0, current.city, edge.targetCity));
                }
            }
        }

        if (best[target].arriveTime == INF)
        {
            cout << "无法找到从起点到终点的路径！" << endl;
            return;
        }

        cout << "\n=== 最快到达方案 ===" << endl;
        cout << "总耗时：" << best[target].arriveTime / 60 << "小时"
             << best[target].arriveTime % 60 << "分钟" << endl;
        cout << "总票价：" << best[target].totalCost << "元" << endl;

        // 打印路径
        printPath(best, target, graph[start], start);
    }

    // 最省钱到达（费用优先）
    void cheapestPath(int start, int target, TransportType type)
    {
        const double INF = 1e18;
        vector<CostNode> best(cities.size());
        vector<bool> visited(cities.size(), false);

        for (size_t i = 0; i < cities.size(); i++)
        {
            best[i].totalCost = INF;
            best[i].arriveTime = INF;
        }

        best[start].totalCost = 0;
        best[start].city = start;
        best[start].prevCity = -1;

        priority_queue<CostNode, vector<CostNode>, greater<CostNode>> pq;
        pq.push(CostNode(start, 0, 0, -1, -1));

        while (!pq.empty())
        {
            CostNode current = pq.top();
            pq.pop();

            if (visited[current.city])
                continue;
            visited[current.city] = true;

            if (current.city == target)
                break;

            for (const Edge &edge : graph[current.city])
            {
                if (edge.type != type)
                    continue;

                double newCost = current.totalCost + edge.cost;

                if (newCost < best[edge.targetCity].totalCost)
                {
                    best[edge.targetCity].totalCost = newCost;
                    best[edge.targetCity].prevCity = current.city;
                    best[edge.targetCity].edgeIndex = edge.targetCity;
                    best[edge.targetCity].arriveTime = current.arriveTime + edge.duration;
                    pq.push(CostNode(edge.targetCity, newCost,
                                     current.arriveTime + edge.duration, current.city, edge.targetCity));
                }
            }
        }

        if (best[target].totalCost == INF)
        {
            cout << "无法找到从起点到终点的路径！" << endl;
            return;
        }

        cout << "\n=== 最省钱到达方案 ===" << endl;
        cout << "总票价：" << best[target].totalCost << "元" << endl;

        printCostPath(best, target, graph[start], start);
    }

    // 中转次数最少（选做）
    void minTransferPath(int start, int target, TransportType type)
    {
        const int INF = INT_MAX;
        vector<TransferNode> best(cities.size());
        vector<bool> visited(cities.size(), false);

        for (size_t i = 0; i < cities.size(); i++)
        {
            best[i].transfers = INF;
            best[i].arriveTime = INF;
        }

        best[start].transfers = 0;
        best[start].city = start;
        best[start].prevCity = -1;

        queue<TransferNode> q;
        q.push(TransferNode(start, 0, 0, -1, -1));

        while (!q.empty())
        {
            TransferNode current = q.front();
            q.pop();

            if (current.city == target)
                break;

            for (const Edge &edge : graph[current.city])
            {
                if (edge.type != type)
                    continue;

                int newTransfers = current.transfers + 1;

                if (newTransfers < best[edge.targetCity].transfers)
                {
                    best[edge.targetCity].transfers = newTransfers;
                    best[edge.targetCity].prevCity = current.city;
                    best[edge.targetCity].edgeIndex = edge.targetCity;
                    q.push(TransferNode(edge.targetCity, newTransfers, 0, current.city, edge.targetCity));
                }
            }
        }

        if (best[target].transfers == INF)
        {
            cout << "无法找到从起点到终点的路径！" << endl;
            return;
        }

        cout << "\n=== 中转次数最少方案 ===" << endl;
        cout << "中转次数：" << best[target].transfers << endl;

        // 打印路径
        vector<pair<int, int>> path;
        int curr = target;
        while (curr != start)
        {
            path.push_back({curr, best[curr].edgeIndex});
            curr = best[curr].prevCity;
        }

        cout << "路线: ";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << cities[path[i].first].name;
            if (i > 0)
                cout << " -> ";
        }
        cout << endl;
    }

    // 主查询接口
    void query()
    {
        string startCity, targetCity;
        int transportChoice, decisionChoice;

        cout << "\n=== 交通咨询查询 ===" << endl;
        listCities();

        cout << "请输入起始城市: ";
        cin.ignore();
        getline(cin, startCity);
        cout << "请输入目的城市: ";
        getline(cin, targetCity);

        int startId = findCityId(startCity);
        int targetId = findCityId(targetCity);

        if (startId == -1 || targetId == -1)
        {
            cout << "城市不存在！" << endl;
            return;
        }

        cout << "请选择交通工具：1.火车  2.飞机" << endl;
        cin >> transportChoice;
        TransportType type = (transportChoice == 1) ? TRAIN : PLANE;

        cout << "请选择决策原则：1.最快到达  2.最省钱到达  3.中转次数最少" << endl;
        cin >> decisionChoice;

        switch (decisionChoice)
        {
        case 1:
            fastestPath(startId, targetId, type);
            break;
        case 2:
            cheapestPath(startId, targetId, type);
            break;
        case 3:
            minTransferPath(startId, targetId, type);
            break;
        default:
            cout << "无效选择！" << endl;
        }
    }

    // ==================== 菜单 ====================

    void showMenu()
    {
        cout << "\n========== 全国交通咨询模拟系统 ==========" << endl;
        cout << "【城市管理】" << endl;
        cout << "1. 查看城市列表" << endl;
        cout << "2. 添加城市" << endl;
        cout << "3. 删除城市" << endl;
        cout << endl;
        cout << "【交通数据管理】" << endl;
        cout << "4. 添加车次/航班" << endl;
        cout << "5. 删除车次/航班" << endl;
        cout << endl;
        cout << "【交通咨询】" << endl;
        cout << "6. 查询路线" << endl;
        cout << endl;
        cout << "【系统】" << endl;
        cout << "7. 保存数据" << endl;
        cout << "0. 退出系统" << endl;
        cout << "==========================================" << endl;
        cout << "请选择操作: ";
    }
};

// ==================== 主函数 ====================

int main()
{
    cout << "欢迎使用全国交通咨询模拟系统！" << endl;

    TrafficSystem system;

    int choice;
    while (true)
    {
        system.showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.listCities();
            break;
        case 2:
            system.addCity();
            break;
        case 3:
            system.deleteCity();
            break;
        case 4:
            system.addSchedule();
            break;
        case 5:
            system.deleteSchedule();
            break;
        case 6:
            system.query();
            break;
        case 7:
            system.saveData();
            break;
        case 0:
            cout << "正在保存数据并退出..." << endl;
            system.saveData();
            return 0;
        default:
            cout << "无效输入，请重新选择！" << endl;
        }
    }

    return 0;
}