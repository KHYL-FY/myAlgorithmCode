#ifndef TRANS
#define TRANS

#include <vector>
#include <map>
#include <regex>
#include <queue>
#include <iomanip>
#include <fstream>
#include <tuple>
#include "Time.h"
#include "mineException.h"

struct info
{
    std::string way;       // 出行方式
    std::string startCity; // 起点
    std::string endCity;   // 终点
    std::string transName; // 列车或飞机 班号
    Time startTime;        // 出发时间
    Time endTime;          // 到达时间
    int cost;              // 费用
    friend std::istream &operator>>(std::istream &cin, info &a)
    {
        cin >> a.way >> a.startCity >> a.endCity >> a.transName >> a.startTime >> a.endTime >> a.cost;
        return cin;
    }
    friend std::ostream &operator<<(std::ostream &cout, info &a)
    {
        cout << a.way << " ";
        cout << a.startTime << " " << a.startCity << "---> ";
        cout << a.endCity << " " << a.endTime << " ";

        cout << std::setw(8) << a.transName << " ";
        cout << "费用:" << std::setw(6) << a.cost << "元";

        return cout;
    }
};
struct node
{
    int id;
    int w;
    node(int a, int b) : id(a), w(b) {}
    bool operator<(const node &a) const
    {
        return w > a.w;
    }
};
bool cmp(info &a, info &b)
{
    if (a.way != b.way)
        return a.way > b.way;
    if (a.endCity != b.endCity)
        return a.endCity < b.endCity;
    if (a.startTime != b.startTime)
        return a.startTime < b.startTime;
    if (a.endTime != b.endTime)
        return a.endTime < b.endTime;
    return a.cost < b.cost;
}
struct cityinfo
{
    std::string cityName;
    std::vector<info> trans;
};

class TransInformation
{
private:
    std::map<std::string, int> cityID;
    std::vector<bool> visited;
    std::vector<info> pre;
    std::vector<int> distance;
    std::vector<int> arriveTime;

    std::vector<info> cheapestPath;      // 存储最小费用路径的边序列
    std::vector<info> leastTransferPath; // 存储最少中转路径的边序列

    const int INF = 0x3f3f3f3f;
    Time startdep;
    void init();
    void dijkstra_Cost(const std::string &startCity, const std::string &endCity);
    void print_Cheapest_Path();

    void dijkstra_Time(const std::string &startCity);
    void print_Fastest_Path(const std::string &startCity, const std::string &nowCity);

    void BFS_Least_Transfer(const std::string &startCity, const std::string &endCity);
    void print_Least_Transfer_Path();

    /*********************************************************/
    int cityCount = 0;
    std::vector<cityinfo> cityList;
    std::map<std::string, bool> cityUsed;

    void add_City_Info(const std::string &cityName);
    void add_Trans_Info(const info &a);
    void delete_City_Info(const int &n);
    void print_City_Trans_Info(const int &n);
    void print_All_City_Info();
    void delete_Trans_Info(const int &n, const int &m);

public:
    bool cityExists(const std::string &cityName)
    {
        return cityUsed.find(cityName) != cityUsed.end();
    }
    int getCityCount()
    {
        return cityCount;
    }
    bool addCity(const std::string &cityName)
    {
        if (cityUsed[cityName])
        {
            exp::exit(beUsedCityName);
            return false;
        }
        cityCount++;
        add_City_Info(cityName);
        return true;
    }
    bool deleteCity(const std::string &nStr)
    {
        int n;
        std::regex isNumber(R"(\d+)");

        if (!regex_match(nStr, isNumber))
        {
            exp::exit(errorCityID);
            return false;
        }
        else
        {
            n = stoi(nStr);
            if (n <= 0 || n > cityCount)
            {
                exp::exit(errorCityID);
                return false;
            }
        }
        cityCount--;
        cityUsed[cityList[n - 1].cityName] = false;
        delete_City_Info(n);
        return true;
    }
    void printCity()
    {
        if (cityList.empty())
        {
            exp::exit(cityListEmpty);
            return;
        }
        print_All_City_Info();
    }
    void addTrans(const info &a)
    {
        add_Trans_Info(a);
    }
    void printTrans(const int &n)
    {
        print_City_Trans_Info(n);
    }
    void deleteTrans(const int &n, const int &m)
    {
        if (cityList[n - 1].trans.empty())
        {
            exp::exit(transEmpty);
            return;
        }
        delete_Trans_Info(n, m);
    }
    /****************************************************** */
    void searchCheapest(const std::string &startCity, const std::string &endCity)
    {
        dijkstra_Cost(startCity, endCity);
        int cost = distance[cityID[endCity]];
        if (distance[cityID[endCity]] == INF)
        {
            std::cout << "无法到达!" << std::endl;
            return;
        }

        print_Cheapest_Path();
        std::cout << "最小费用为: " << cost << "元" << std::endl;
    }
    void searchFastest(const std::string &startCity, const std::string &endCity)
    {
        dijkstra_Time(startCity);

        if (distance[cityID[endCity]] == INF)
        {
            std::cout << "无法到达!" << std::endl;
            return;
        }

        print_Fastest_Path(startCity, endCity);
        int total = distance[cityID[endCity]] - startdep.toMinutes();
        Time fast(total);
        std::cout << "最短用时: ";
        if (fast.dayOfTime.day > 0)
            std::cout << fast.dayOfTime.day << "天 ";
        std::cout << fast.dayOfTime.Hour << "小时" << fast.dayOfTime.minute << "分钟" << std::endl;
    }
    void searchLeastTransfer(const std::string &startCity, const std::string &endCity)
    {
        BFS_Least_Transfer(startCity, endCity);

        if (distance[cityID[endCity]] == INF)
        {
            std::cout << "无法到达!" << std::endl;
            return;
        }

        print_Least_Transfer_Path();
        std::cout << "最少中转次数: " << distance[cityID[endCity]] - 1 << "次" << std::endl;
    }
    void saveToFile();
};

void TransInformation::saveToFile()
{
    std::ofstream outCity("city.txt");
    if (outCity.is_open())
    {
        for (auto &c : cityList)
        {
            outCity << c.cityName << std::endl;
        }
        outCity.close();
    }
    else
    {
        std::cout << "[系统]: 城市文件保存失败!" << std::endl;
    }

    std::ofstream outTrans("trans.txt");
    if (outTrans.is_open())
    {
        for (auto &c : cityList)
        {
            for (auto &t : c.trans)
            {
                outTrans << t.way << " "
                         << t.startCity << " "
                         << t.endCity << " "
                         << t.transName << " "
                         << t.startTime.dayOfTime.month << " "
                         << t.startTime.dayOfTime.day << " "
                         << t.startTime.dayOfTime.Hour << " "
                         << t.startTime.dayOfTime.minute << " "
                         << t.endTime.dayOfTime.month << " "
                         << t.endTime.dayOfTime.day << " "
                         << t.endTime.dayOfTime.Hour << " "
                         << t.endTime.dayOfTime.minute << " "
                         << t.cost << std::endl;
            }
        }
        outTrans.close();
    }
    else
    {
        std::cout << "[系统]: 交通信息文件保存失败!" << std::endl;
    }
}

void TransInformation::add_City_Info(const std::string &cityName)
{

    cityUsed[cityName] = true;
    cityList.push_back({cityName, std::vector<info>()});
}
void TransInformation::delete_City_Info(const int &n)
{

    cityList.erase(cityList.begin() + n - 1);
    return;
}
void TransInformation::print_All_City_Info()
{
    int p = 0;
    for (auto i = cityList.begin(); i != cityList.end(); i++)
    {
        p++;
        std::cout << std::right << std::setw(8) << p << ".";
        std::cout << (*i).cityName;
        if (p % 4 == 0)
            std::cout << std::endl;
    }

    for (int i = 1; i <= 18 - p / 4; i++)
        std::cout << std::endl;
}

void TransInformation::add_Trans_Info(const info &a)
{
    std::string startCity = a.startCity;
    for (auto i = cityList.begin(); i != cityList.end(); i++)
    {
        if ((*i).cityName == startCity)
        {
            (*i).trans.push_back(a);
            sort((*i).trans.begin(), (*i).trans.end(), cmp);
            return;
        }
    }
}

void TransInformation::print_City_Trans_Info(const int &n)
{
    int p = 0;

    for (auto i = cityList[n - 1].trans.begin(); i != cityList[n - 1].trans.end(); i++)
    {
        p++;
        std::cout << " " << std::setw(3) << p << ".";
        std::cout << (*i) << std::endl;
    }
    for (int i = 1; i <= 18 - p; i++)
        std::cout << std::endl;
}
void TransInformation::delete_Trans_Info(const int &n, const int &m)
{
    cityList[n - 1].trans.erase(cityList[n - 1].trans.begin() + m - 1);
}
void TransInformation::init()
{
    visited.clear();
    pre.clear();
    cityID.clear();
    distance.clear();
    arriveTime.clear();

    distance.resize(cityCount + 5);
    visited.resize(cityCount + 5);
    pre.resize(cityCount + 5);
    arriveTime.resize(cityCount + 5);

    int p = 0;
    for (auto &i : cityList)
    {
        p++;
        cityID[i.cityName] = p;
        distance[p] = INF;
        arriveTime[p] = INF;
    }
}
void TransInformation::dijkstra_Cost(const std::string &startCity, const std::string &endCity)
{
    init();
    cheapestPath.clear();

    // 带到达时间和父节点索引的节点
    struct costNode
    {
        int id;     // 城市编号
        int cost;   // 累计费用
        int arrive; // 到达该城市的时间（分钟）
        int pid;    // 父节点在 parentEdge 中的索引，-1 表示起点
        costNode(int a, int b, int c, int p = -1) : id(a), cost(b), arrive(c), pid(p) {}
        bool operator<(const costNode &a) const
        {
            return cost > a.cost; // 最小费用优先
        }
    };

    // 每个节点维护一组 Pareto 最优标签: (cost, arrive, pid)
    // 标签 A 支配标签 B 当且仅当 A.cost <= B.cost 且 A.arrive <= B.arrive
    std::vector<std::vector<std::tuple<int, int, int>>> labels(cityCount + 5);

    // 用于路径回溯：记录每个入队节点的父节点和对应边
    std::vector<int> parentPid;   // parentPid[i] = 第i个入队节点的父节点pid
    std::vector<info> parentEdge; // parentEdge[i] = 到达第i个入队节点的边
    int pushCount = 0;

    int start = cityID[startCity];
    int endId = cityID[endCity];
    distance[start] = 0;
    arriveTime[start] = 0;
    labels[start].push_back(std::make_tuple(0, 0, -1));

    std::priority_queue<costNode> Q;
    Q.push(costNode(start, 0, 0, -1));

    while (!Q.empty())
    {
        costNode u = Q.top();
        Q.pop();

        // 检查当前标签是否被后续发现的更优标签支配（跳过自身）
        bool dominated = false;
        for (auto &t : labels[u.id])
        {
            int c = std::get<0>(t), a = std::get<1>(t), p = std::get<2>(t);
            if (p != u.pid && c <= u.cost && a <= u.arrive)
            {
                dominated = true;
                break;
            }
        }
        if (dominated)
            continue;

        for (auto &i : cityList[u.id - 1].trans)
        {
            int v = cityID[i.endCity];
            int dep = i.startTime.toMinutes();
            if (dep < u.arrive)
                continue;

            int newCost = u.cost + i.cost;
            int newArrive = i.endTime.toMinutes();

            // 检查新标签是否被已有标签支配
            bool newDominated = false;
            for (auto &t : labels[v])
            {
                int c = std::get<0>(t), a = std::get<1>(t);
                if (c <= newCost && a <= newArrive)
                {
                    newDominated = true;
                    break;
                }
            }
            if (newDominated)
                continue;

            int myPid = pushCount++;
            parentPid.push_back(u.pid);
            parentEdge.push_back(i);

            if (newCost < distance[v])
                distance[v] = newCost;

            // 移除被新标签支配的旧标签
            auto it = labels[v].begin();
            while (it != labels[v].end())
            {
                int c = std::get<0>(*it), a = std::get<1>(*it);
                if (c >= newCost && a >= newArrive)
                    it = labels[v].erase(it);
                else
                    ++it;
            }
            labels[v].push_back(std::make_tuple(newCost, newArrive, myPid));
            Q.push(costNode(v, newCost, newArrive, myPid));
        }
    }

    if (distance[endId] == INF)
        return;

    // 从终点标签中找到最小费用的那条路径
    int bestPid = -1, bestCost = INF;
    for (auto &t : labels[endId])
    {
        int c = std::get<0>(t), p = std::get<2>(t);
        if (c < bestCost)
        {
            bestCost = c;
            bestPid = p;
        }
    }

    // 从 bestPid 回溯构建路径
    std::vector<info> revPath;
    int cur = bestPid;
    while (cur >= 0)
    {
        revPath.push_back(parentEdge[cur]);
        cur = parentPid[cur];
    }
    for (int i = (int)revPath.size() - 1; i >= 0; i--)
        cheapestPath.push_back(revPath[i]);
}
void TransInformation::print_Cheapest_Path()
{
    for (auto &edge : cheapestPath)
        std::cout << edge << std::endl;
}
void TransInformation::dijkstra_Time(const std::string &startCity)
{
    init();

    int start = cityID[startCity];
    distance[start] = 0;
    arriveTime[start] = 0;
    std::priority_queue<node> Q;
    Q.push(node(start, 0));

    while (!Q.empty())
    {
        node u = Q.top();
        Q.pop();
        if (visited[u.id])
            continue;
        visited[u.id] = true;

        for (auto &i : cityList[u.id - 1].trans)
        {
            int v = cityID[i.endCity];
            if (visited[v])
                continue;

            int dep = i.startTime.toMinutes();
            int arr = i.endTime.toMinutes();

            if (dep < arriveTime[u.id])
                continue;

            if (distance[v] > arr)
            {
                distance[v] = arr;
                arriveTime[v] = arr;
                Q.push(node(v, distance[v]));
                pre[v] = i;
            }
        }
    }
}
void TransInformation::print_Fastest_Path(const std::string &startCity, const std::string &nowCity)
{
    if (pre[cityID[nowCity]].startCity == startCity)
        startdep = pre[cityID[nowCity]].startTime;
    else
        print_Fastest_Path(startCity, pre[cityID[nowCity]].startCity);

    std::cout << pre[cityID[nowCity]] << std::endl;
}
void TransInformation::BFS_Least_Transfer(const std::string &startCity, const std::string &endCity)
{
    init();
    leastTransferPath.clear();

    struct bfsNode
    {
        int id, transfers, arrive, pid;
        bfsNode(int a, int b, int c, int p = -1) : id(a), transfers(b), arrive(c), pid(p) {}
        bool operator<(const bfsNode &a) const { return transfers > a.transfers; }
    };

    std::vector<int> parentPid;
    std::vector<info> parentEdge;
    std::vector<int> bestPidForCity(cityCount + 5, -1);
    int pushCount = 0;

    int start = cityID[startCity];
    int endId = cityID[endCity];
    distance[start] = 0;
    arriveTime[start] = 0;
    std::priority_queue<bfsNode> Q;
    Q.push(bfsNode(start, 0, 0, -1));

    while (!Q.empty())
    {
        bfsNode u = Q.top();
        Q.pop();

        if (u.transfers > distance[u.id] && u.arrive > arriveTime[u.id])
            continue;

        for (auto &i : cityList[u.id - 1].trans)
        {
            int v = cityID[i.endCity];

            int dep = i.startTime.toMinutes();
            if (dep < u.arrive)
                continue;

            int newTransfers = u.transfers + 1;
            int newArrive = i.endTime.toMinutes();

            if (newTransfers < distance[v] || newArrive < arriveTime[v])
            {
                int myPid = pushCount++;
                parentPid.push_back(u.pid);
                parentEdge.push_back(i);

                if (newTransfers < distance[v])
                {
                    distance[v] = newTransfers;
                    bestPidForCity[v] = myPid;
                }
                if (newArrive < arriveTime[v])
                    arriveTime[v] = newArrive;
                Q.push(bfsNode(v, newTransfers, newArrive, myPid));
            }
        }
    }

    if (distance[endId] == INF)
        return;

    std::vector<info> revPath;
    int cur = bestPidForCity[endId];
    while (cur >= 0)
    {
        revPath.push_back(parentEdge[cur]);
        cur = parentPid[cur];
    }
    for (int i = (int)revPath.size() - 1; i >= 0; i--)
        leastTransferPath.push_back(revPath[i]);
}

void TransInformation::print_Least_Transfer_Path()
{
    for (auto &edge : leastTransferPath)
        std::cout << edge << std::endl;
}
#endif