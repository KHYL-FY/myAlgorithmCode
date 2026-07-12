#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <conio.h>
#include <iomanip>

using namespace std;

#define MAX_LEN 80 // 控制台标准行宽
#define MAX_CITY 50
#define TOP 666666

// 时间结构
typedef struct
{
    int hour;
    int minute;
} Time;

// 边节点（邻接表节点）
typedef struct EdgeNode
{
    int toCity;            // 到达城市ID
    string vehicleId;      // 车次/航班号
    Time startTime;        // 出发时间
    Time endTime;          // 到达时间
    int cost;              // 票价
    string vehicleType;    // 交通工具类型
    string flightDays;     // 航班期（仅飞机用）
    string model;          // 机型（仅飞机用）
    struct EdgeNode *next; // 指向下一个边节点
} EdgeNode;

// 顶点节点（邻接表头节点）
typedef struct
{
    string cityName;     // 城市名称
    int cityId;          // 城市ID
    EdgeNode *firstEdge; // 指向第一条边
} City;

// 图结构
typedef struct
{
    City cities[MAX_CITY]; // 顶点数组（城市）
    int cityCount;         // 顶点数量（城市）
    string vehicleType;    // 交通工具类型
} Graph;

// 全局图变量
Graph trainGraph;       // 火车交通图
Graph planeGraph;       // 飞机交通图
Graph combinedGraph;    // 综合交通图
bool g_autoSave = true; // 自动保存开关（加载数据时关闭，防止覆盖源文件）

// ========== 图的基本操作 ==========

// 初始化图
void initGraph(Graph &g)
{
    g.cityCount = 0;
    for (int i = 0; i < MAX_CITY; i++)
    {
        g.cities[i].firstEdge = NULL;
        g.cities[i].cityId = -1;
        g.cities[i].cityName = "";
    }
}

// 查找城市在图中是否存在，返回索引
int findVertex(Graph *g, const string &cityName)
{
    for (int i = 0; i < g->cityCount; i++)
    {
        if (g->cities[i].cityName == cityName)
        {
            return i;
        }
    }
    return -1;
}

// 添加城市
void syncCombinedGraph();
void write(Graph &g);
void addCity(Graph &g, const string &cityName)
{
    if (g.cityCount >= MAX_CITY)
    {
        cout << "【×】不好意思，城市数量已达上限，无法再继续添加新城市" << endl;
        return;
    }
    if (findVertex(&g, cityName) != -1)
    {
        cout << "【×】您所要添加的城市【" << cityName << "】已存在，无需重复添加" << endl;
        return;
    }
    else
    {
        g.cities[g.cityCount].cityName = cityName;
        g.cities[g.cityCount].cityId = g.cityCount;
        g.cities[g.cityCount].firstEdge = NULL;
        g.cityCount++;
        cout << "【√】成功在“" << g.vehicleType << "交通图”中添加城市【" << cityName << "】！" << endl;
    }
    if (g_autoSave && (g.vehicleType == "火车" || g.vehicleType == "飞机"))
    {
        write(g);
        syncCombinedGraph();
    }
}

// 删除城市及其所有边
void deleteCity(Graph *g, const string &cityName)
{
    int index = findVertex(g, cityName);
    if (index == -1)
    {
        cout << "【×】不好意思，“" << g->vehicleType << "交通图”中不存在城市【" << cityName << "】" << endl;
        return;
    }

    // 释放该顶点的所有边
    EdgeNode *p = g->cities[index].firstEdge;
    while (p != NULL)
    {
        EdgeNode *temp = p;
        p = p->next;
        delete temp;
    }

    // 删除其他顶点指向该城市的边
    // 遍历图中所有顶点 i
    for (int i = 0; i < g->cityCount; i++)
    {
        EdgeNode *prev = NULL;                   // 记录当前边的前驱结点
        EdgeNode *curr = g->cities[i].firstEdge; // 从顶点 i 的第一条边开始遍历
        // 遍历顶点 i 的所有出边链表
        while (curr != NULL)
        {
            // 如果当前边指向要删除的顶点
            if (curr->toCity == index)
            {
                // 情况1：要删除的边是链表的头结点
                if (prev == NULL)
                {
                    // 直接把顶点 i 的 firstEdge 指向当前边的下一个结点
                    g->cities[i].firstEdge = curr->next;
                    // 情况2：要删除的边在链表中间/尾部
                }
                else
                {
                    // 让前驱节点直接跳过当前边，指向当前边的下一个结点
                    prev->next = curr->next;
                }
                // 释放被删除边的内存，防止内存泄露
                EdgeNode *temp = curr;
                curr = curr->next; // 先移动指针，再释放
                delete temp;
            }
            else
            { // 当前边不指向 index，正常向后遍历
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // 1.将后面的顶点前移
    for (int i = index; i < g->cityCount - 1; i++)
    {
        g->cities[i] = g->cities[i + 1];
        g->cities[i].cityId = i;
    }
    g->cityCount--;
    // 2.全局修正所有边的toCity，所有大于index的编号全部减1
    for (int j = 0; j < g->cityCount; j++)
    {
        EdgeNode *p = g->cities[j].firstEdge;
        while (p != NULL)
        {
            if (p->toCity > index)
                p->toCity -= 1;
            p = p->next;
        }
    }
    cout << "【√】成功在“" << g->vehicleType << "交通图”中删除城市【" << cityName << "】！" << endl;
    if (g_autoSave && (g->vehicleType == "火车" || g->vehicleType == "飞机"))
    {
        write(*g);
        syncCombinedGraph();
    }
}

// 添加边（班次）
void addEdge(Graph *g, const string &from, const string &to, const string &vehicleId,
             Time startTime, Time endTime, int cost, string vehicleType,
             const string &flightDays, const string &model)
{
    int fromIndex = findVertex(g, from);
    int toIndex = findVertex(g, to);

    if (fromIndex == -1)
    {
        cout << "当前“" << g->vehicleType << "交通图”中不存在城市【" << from << "】，若要添加此班次，请先添加城市" << endl;
        return;
    }
    else if (toIndex == -1)
    {
        cout << "当前“" << g->vehicleType << "交通图”中不存在城市【" << to << "】，若要添加此班次，请先添加城市" << endl;
        return;
    }
    else if (fromIndex == -1 && toIndex == -1)
    {
        cout << "当前“" << g->vehicleType << "交通图”中不存在城市【" << from << "】和【" << to << "】，若要添加此班次，请先添加城市" << endl;
        return;
    }
    // 创建新的边节点
    EdgeNode *newEdge = new EdgeNode();
    newEdge->toCity = toIndex;
    newEdge->vehicleId = vehicleId;
    newEdge->startTime = startTime;
    newEdge->endTime = endTime;
    newEdge->cost = cost;
    newEdge->vehicleType = vehicleType;
    newEdge->flightDays = flightDays;
    newEdge->model = model;
    newEdge->next = NULL;

    // 插入到邻接表头部（头插法）
    newEdge->next = g->cities[fromIndex].firstEdge;
    g->cities[fromIndex].firstEdge = newEdge;

    cout << "【√】成功在“" << g->vehicleType << "交通图”中添加【"
         << newEdge->vehicleType << "】班次【" << vehicleId << "】！" << endl;
    if (g_autoSave && (g->vehicleType == "火车" || g->vehicleType == "飞机"))
    {
        write(*g);
        syncCombinedGraph();
    }
}

// 删除边（班次）
void deleteEdge(Graph *g, const string &vehicleId)
{
    int found = 0;
    // 遍历图中所有城市（顶点）
    for (int i = 0; i < g->cityCount; i++)
    {
        EdgeNode *prev = NULL;
        EdgeNode *curr = g->cities[i].firstEdge;
        // 遍历当前城市的所有出边（班次链表）
        while (curr != NULL)
        {
            if (curr->vehicleId == vehicleId)
            {
                if (prev == NULL)
                {
                    g->cities[i].firstEdge = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                found = 1;
                cout << "【√】成功删除“" << g->vehicleType
                     << "交通图中”班次为【" << vehicleId << "】的"
                     << g->vehicleType << "！" << endl;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (found)
            break;
    }
    if (!found)
    {
        cout << "【×】不好意思，您所要删除的班次【" << vehicleId << "】不存在！" << endl;
        return;
    }
    if (g_autoSave && (g->vehicleType == "火车" || g->vehicleType == "飞机"))
    {
        write(*g);
        syncCombinedGraph();
    }
}

// 显示图的所有边
void showGraph(Graph *g)
{
    cout << "\n═══════════════════════════════════════════════════════════════════════" << endl;
    cout << "【" << g->vehicleType << "交通图】：" << endl;
    for (int i = 0; i < g->cityCount; i++)
    {
        EdgeNode *p = g->cities[i].firstEdge;
        while (p != NULL)
        {
            cout << "【" << g->cities[i].cityName << "】" << " → "
                 << "【" << g->cities[p->toCity].cityName << "】: "
                 << p->vehicleId << "  "
                 << setw(2) << setfill('0') << p->startTime.hour << ":"
                 << setw(2) << setfill('0') << p->startTime.minute << "→"
                 << setw(2) << setfill('0') << p->endTime.hour << ":"
                 << setw(2) << setfill('0') << p->endTime.minute
                 << "  票价:" << p->cost << "元";
            if (p->vehicleType == "飞机")
            {
                cout << "  " << p->flightDays << " " << p->model;
            }
            cout << endl;
            p = p->next;
        }
    }
    cout << "═══════════════════════════════════════════════════════════════════════" << endl;
}

// ========== 辅助函数 ==========

// 时间转换为分钟
int timeToMinutes(Time t)
{
    return t.hour * 60 + t.minute;
}

// 分钟转换为时间
Time minutesToTime(int minutes)
{
    Time t;
    t.hour = minutes / 60;
    t.minute = minutes % 60;
    return t;
}

// 解析时间字符串
Time parseTime(const string &str)
{
    Time t;
    sscanf(str.c_str(), "%d:%d", &t.hour, &t.minute);
    return t;
}

// 计算等待时间
int calcWaitTime(Time arrive, Time depart)
{
    int arriveMin = timeToMinutes(arrive);
    int departMin = timeToMinutes(depart);
    if (arriveMin <= departMin)
    {
        return departMin - arriveMin;
    }
    else
    {
        return 1440 - arriveMin + departMin;
    }
}

// 计算行程时长
int calcDuration(Time start, Time end)
{
    int startMin = timeToMinutes(start);
    int endMin = timeToMinutes(end);
    if (endMin >= startMin)
    {
        return endMin - startMin;
    }
    else
    {
        return 1440 - startMin + endMin;
    }
}

// ========== Dijkstra算法（基于邻接表） ==========

// 路径状态结构
typedef struct
{
    int totalTime;      // 总耗时
    int totalCost;      // 总花费
    int transferCount;  // 中转次数
    int preCity;        // 前驱城市索引
    EdgeNode *prevEdge; // 乘坐的班次（边节点指针）
    Time arriveTime;    // 到达时间
} Path;

// 最快到达（基于邻接表）
void fastestPath(Graph *g, int startIndex, int endIndex)
{
    Path path[MAX_CITY];
    int visited[MAX_CITY] = {0};

    // 初始化
    for (int i = 0; i < g->cityCount; i++)
    {
        path[i].totalTime = TOP;
        path[i].preCity = -1;
        path[i].prevEdge = NULL;
        path[i].arriveTime.hour = 0;
        path[i].arriveTime.minute = 0;
    }
    path[startIndex].totalTime = 0;
    path[startIndex].totalCost = 0;
    path[startIndex].arriveTime.hour = 0;
    path[startIndex].arriveTime.minute = 0;

    for (int k = 0; k < g->cityCount; k++)
    {
        // 找未访问中总时间最小的城市
        int begin = -1, minTime = TOP;
        for (int i = 0; i < g->cityCount; i++)
        {
            if (!visited[i] && path[i].totalTime < minTime)
            {
                minTime = path[i].totalTime;
                begin = i;
            }
        }
        if (begin == -1 || begin == endIndex)
            break;
        visited[begin] = 1;

        // 遍历邻接表（从u出发的所有班次）
        EdgeNode *p = g->cities[begin].firstEdge;
        while (p != NULL)
        {
            int arrival = p->toCity;
            int waitTime = calcWaitTime(path[begin].arriveTime, p->startTime);
            int duration = calcDuration(p->startTime, p->endTime);
            int newTotalTime = path[begin].totalTime + waitTime + duration;

            if (newTotalTime < path[arrival].totalTime)
            {
                path[arrival].totalTime = newTotalTime;
                path[arrival].totalCost = path[begin].totalCost + p->cost;
                path[arrival].preCity = begin;
                path[arrival].prevEdge = p;
                path[arrival].arriveTime = p->endTime;
            }
            p = p->next;
        }
    }

    // 输出结果
    if (path[endIndex].totalTime == TOP)
    {
        cout << "【×】无法到达！" << endl;
        return;
    }

    // 回溯路径
    typedef struct
    {
        int passCity[MAX_CITY];       // 存储路径上的城市索引（数组形式）
        EdgeNode *pathEdge[MAX_CITY]; // 存储路径上需要乘坐的车次/班次
        int Length;                   // 路径长度
    } Paths;
    Paths paths;
    paths.Length = 0;
    int curr = endIndex; // 从终点开始回溯

    while (curr != startIndex)
    {
        paths.passCity[paths.Length] = curr;
        paths.pathEdge[paths.Length] = path[curr].prevEdge;
        curr = path[curr].preCity;
        paths.Length++; // 路径长度+1
    }
    paths.passCity[paths.Length] = startIndex;

    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                     最快到达方案                           ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ 总耗时：" << setw(2) << (path[endIndex].totalTime - timeToMinutes((paths.pathEdge[paths.Length - 1])->startTime)) / 60 << " 小时 "
         << setw(2) << (path[endIndex].totalTime - timeToMinutes((paths.pathEdge[paths.Length - 1])->startTime)) % 60 << " 分钟                                    ║" << endl;
    cout << "║ 总费用：" <<setw(4)<< path[endIndex].totalCost << " 元                                            ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║                      详细行程：                            ║" << endl;

    // 逆序输出
    for (int i = paths.Length; i > 0; i--)
    {
        int begin = paths.passCity[i];       // 当前路径的起点城市的索引
        int arrival = paths.passCity[i - 1]; // 当前路径的终点城市的索引
        EdgeNode *edge = paths.pathEdge[i - 1];

        cout << "║ " << g->cities[begin].cityName << " → " << g->cities[arrival].cityName
             << ": 乘坐" << edge->vehicleType
             << ", " << setw(2) << setfill('0') << edge->startTime.hour
             << ":" << setw(2) << setfill('0') << edge->startTime.minute
             << "出发 " << setw(2) << setfill('0') << edge->endTime.hour
             << ":" << setw(2) << setfill('0') << edge->endTime.minute
             << "到达, 票价" <<setw(4)<< edge->cost << "元     ║\n";
    }
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
}
// 最省钱到达（基于邻接表）
void cheapestPath(Graph *g, int startIndex, int endIndex)
{
    Path path[MAX_CITY];
    int visited[MAX_CITY] = {0};

    for (int i = 0; i < g->cityCount; i++)
    {
        path[i].totalCost = TOP;
        path[i].preCity = -1;
        path[i].prevEdge = NULL;
    }
    path[startIndex].totalCost = 0;

    // Dijkstra主循环
    for (int k = 0; k < g->cityCount; k++)
    {
        int begin = -1, minCost = TOP;
        for (int i = 0; i < g->cityCount; i++)
        {
            if (!visited[i] && path[i].totalCost < minCost)
            {
                minCost = path[i].totalCost;
                begin = i;
            }
        }
        if (begin == -1 || begin == endIndex)
            break;
        visited[begin] = 1;

        EdgeNode *p = g->cities[begin].firstEdge;
        while (p != NULL)
        {
            int arrival = p->toCity;
            int newCost = path[begin].totalCost + p->cost;
            if (newCost < path[arrival].totalCost)
            {
                path[arrival].totalCost = newCost;
                path[arrival].preCity = begin;
                path[arrival].prevEdge = p;
            }
            p = p->next;
        }
    }

    if (path[endIndex].totalCost == TOP)
    {
        cout << "\n【×】无法到达！" << endl;
        return;
    }

    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                     最省钱到达方案                         ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ 总费用：" << path[endIndex].totalCost << " 元                                            ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║                      详细行程：                            ║" << endl;

    int passCity[MAX_CITY];
    EdgeNode *pathEdge[MAX_CITY];
    int Length = 0;
    int curr = endIndex;

    while (curr != startIndex)
    {
        passCity[Length] = curr;
        pathEdge[Length] = path[curr].prevEdge;
        curr = path[curr].preCity;
        Length++;
    }
    passCity[Length] = startIndex;

    for (int i = Length; i > 0; i--)
    {
        int begin = passCity[i];
        int arrival = passCity[i - 1];
        EdgeNode *edge = pathEdge[i - 1];
        cout << "║ " << g->cities[begin].cityName << " → " << g->cities[arrival].cityName
             << "：乘坐" << g->vehicleType << " " << edge->vehicleId
             << "，票价" << edge->cost << "元                    ║" << endl;
    }
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
}

// 中转次数最少（BFS，基于邻接表）
void minTransferPath(Graph *g, int startIndex, int endIndex)
{
    int dist[MAX_CITY];
    int preCity[MAX_CITY];
    EdgeNode *prevEdge[MAX_CITY];
    int queue[MAX_CITY], front = 0, rear = 0;
    int visited[MAX_CITY] = {0};

    for (int i = 0; i < g->cityCount; i++)
    {
        dist[i] = TOP;
        preCity[i] = -1;
        prevEdge[i] = NULL;
    }

    dist[startIndex] = 0;
    visited[startIndex] = 1;
    queue[rear++] = startIndex;

    while (front < rear)
    {
        int begin = queue[front++];

        EdgeNode *p = g->cities[begin].firstEdge;
        while (p != NULL)
        {
            int arrival = p->toCity;
            if (!visited[arrival])
            {
                visited[arrival] = 1;
                dist[arrival] = dist[begin] + 1;
                preCity[arrival] = begin;
                prevEdge[arrival] = p;
                queue[rear++] = arrival;
            }
            p = p->next;
        }
    }

    if (dist[endIndex] == TOP)
    {
        cout << "\n【×】无法到达！" << endl;
        return;
    }

    cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    中转次数最少方案                  ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ 中转次数：" << dist[endIndex] - 1 << " 次                                             ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════╣" << endl;
    cout << "║                      详细行程：                            ║" << endl;

    int passCity[MAX_CITY];
    EdgeNode *pathEdge[MAX_CITY];
    int Length = 0;
    int curr = endIndex;

    while (curr != startIndex)
    {
        passCity[Length] = curr;
        pathEdge[Length] = prevEdge[curr];
        curr = preCity[curr];
        Length++;
    }
    passCity[Length] = startIndex;

    for (int i = Length; i > 0; i--)
    {
        int begin = passCity[i];
        int arrival = passCity[i - 1];
        EdgeNode *edge = pathEdge[i - 1];
        cout << "║ " << g->cities[begin].cityName << " → " << g->cities[arrival].cityName
             << "：乘坐" << g->vehicleType << " " << edge->vehicleId << "，"
             << setw(2) << setfill('0') << edge->startTime.hour << ":"
             << setw(2) << setfill('0') << edge->startTime.minute << "出发 "
             << setw(2) << setfill('0') << edge->endTime.hour << ":"
             << setw(2) << setfill('0') << edge->endTime.minute << "到达           ║" << endl;
    }
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
}

// ========== 数据初始化 ==========

void runingData(Graph &g)
{
    ifstream fp; // 文件流对象
    if (g.vehicleType == "火车")
    {
        fp.open("train.txt");
    }
    else if (g.vehicleType == "飞机")
    {
        fp.open("plane.txt");
    }

    if (!fp.is_open())
    {
        cout << "【×】文件打开失败" << endl;
        return;
    }

    initGraph(g);
    string line;

    getline(fp, line);
    getline(fp, line);

    // 读取城市行
    getline(fp, line);

    // 关闭自动保存，防止加载过程中覆盖源文件
    g_autoSave = false;

    // 使用stringstream解析所有城市
    stringstream ss(line);
    string city;
    while (ss >> city)
    {
        addCity(g, city);
    }

    getline(fp, line);

    // 读取车次信息
    while (getline(fp, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        stringstream ss_line(line);
        string start, end, id, time1, time2, vehicleType, period, planType;
        int price;

        ss_line >> start >> end >> id >> time1 >> time2 >> price >> vehicleType >> period >> planType;

        addEdge(&g, start, end, id,
                parseTime(time1), parseTime(time2),
                price, vehicleType, period, planType);
    }

    fp.close();

    // 加载完成，重新启用自动保存，并写入一次确保文件完整
    g_autoSave = true;
    write(g);
    if (g.vehicleType == "火车" || g.vehicleType == "飞机")
    {
        syncCombinedGraph();
    }
}

// 数据写入
void write(Graph &g)
{
    ofstream fp;
    if (g.vehicleType == "火车")
    {
        fp.open("train.txt");
    }
    else if (g.vehicleType == "飞机")
    {
        fp.open("plane.txt");
    }
    else
    {
        fp.open("combined.txt");
    }

    if (!fp.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }

    // 写入头注释
    fp << "#" << g.vehicleType << "交通图数据" << endl;
    fp << "# 城市列表（空格分隔）" << endl;

    // 1. 写入所有城市（一行，空格分隔）
    for (int i = 0; i < g.cityCount; i++)
    {
        if (i > 0)
            fp << " ";
        fp << g.cities[i].cityName;
    }
    fp << endl;

    // 2. 写入注释和表头
    fp << "# 起点 终点 车次/航班号 出发时间 到达时间 票价 交通工具类型 航班期（仅飞机用） 机型（仅飞机用）" << endl;

    // 3. 写入所有班次
    for (int i = 0; i < g.cityCount; i++)
    {
        EdgeNode *p = g.cities[i].firstEdge;
        while (p != NULL)
        {
            string from = g.cities[i].cityName;
            string to = g.cities[p->toCity].cityName;
            fp << from << " "
               << to << " "
               << p->vehicleId << " "
               << setw(2) << setfill('0') << p->startTime.hour << ":"
               << setw(2) << setfill('0') << p->startTime.minute << " "
               << setw(2) << setfill('0') << p->endTime.hour << ":"
               << setw(2) << setfill('0') << p->endTime.minute << " "
               << p->cost << " "
               << p->vehicleType << " " // 交通工具类型
               << p->flightDays << " "
               << p->model << endl;
            p = p->next;
        }
    }

    fp.close();
}
// 同步综合交通图（从火车图和飞机图重新构建）
void syncCombinedGraph()
{
    // 1. 清空综合图
    initGraph(combinedGraph);
    combinedGraph.vehicleType = "综合";

    // 2. 添加所有城市（去重）
    // 先统计火车图的城市
    for (int i = 0; i < trainGraph.cityCount; i++)
    {
        string cityName = trainGraph.cities[i].cityName;
        // 检查是否已存在
        bool exists = false;
        for (int j = 0; j < combinedGraph.cityCount; j++)
        {
            if (combinedGraph.cities[j].cityName == cityName)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            combinedGraph.cities[combinedGraph.cityCount].cityName = cityName;
            combinedGraph.cities[combinedGraph.cityCount].cityId = combinedGraph.cityCount;
            combinedGraph.cities[combinedGraph.cityCount].firstEdge = NULL;
            combinedGraph.cityCount++;
        }
    }

    // 添加飞机图的城市
    for (int i = 0; i < planeGraph.cityCount; i++)
    {
        string cityName = planeGraph.cities[i].cityName;
        bool exists = false;
        for (int j = 0; j < combinedGraph.cityCount; j++)
        {
            if (combinedGraph.cities[j].cityName == cityName)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            combinedGraph.cities[combinedGraph.cityCount].cityName = cityName;
            combinedGraph.cities[combinedGraph.cityCount].cityId = combinedGraph.cityCount;
            combinedGraph.cities[combinedGraph.cityCount].firstEdge = NULL;
            combinedGraph.cityCount++;
        }
    }

    // 3. 添加所有火车班次
    for (int i = 0; i < trainGraph.cityCount; i++)
    {
        EdgeNode *p = trainGraph.cities[i].firstEdge;
        while (p != NULL)
        {
            // 查找起点和终点在综合图中的索引
            string fromName = trainGraph.cities[i].cityName;
            string toName = trainGraph.cities[p->toCity].cityName;

            int fromIndex = -1, toIndex = -1;
            for (int j = 0; j < combinedGraph.cityCount; j++)
            {
                if (combinedGraph.cities[j].cityName == fromName)
                    fromIndex = j;
                if (combinedGraph.cities[j].cityName == toName)
                    toIndex = j;
            }

            if (fromIndex != -1 && toIndex != -1)
            {
                // 创建新边节点
                EdgeNode *newEdge = new EdgeNode();
                newEdge->toCity = toIndex;
                newEdge->vehicleId = p->vehicleId;
                newEdge->startTime = p->startTime;
                newEdge->endTime = p->endTime;
                newEdge->cost = p->cost;
                newEdge->vehicleType = p->vehicleType;
                newEdge->flightDays = p->flightDays;
                newEdge->model = p->model;
                newEdge->next = combinedGraph.cities[fromIndex].firstEdge;
                combinedGraph.cities[fromIndex].firstEdge = newEdge;
            }
            p = p->next;
        }
    }

    // 4. 添加所有飞机班次
    for (int i = 0; i < planeGraph.cityCount; i++)
    {
        EdgeNode *p = planeGraph.cities[i].firstEdge;
        while (p != NULL)
        {
            string fromName = planeGraph.cities[i].cityName;
            string toName = planeGraph.cities[p->toCity].cityName;

            int fromIndex = -1, toIndex = -1;
            for (int j = 0; j < combinedGraph.cityCount; j++)
            {
                if (combinedGraph.cities[j].cityName == fromName)
                    fromIndex = j;
                if (combinedGraph.cities[j].cityName == toName)
                    toIndex = j;
            }

            if (fromIndex != -1 && toIndex != -1)
            {
                EdgeNode *newEdge = new EdgeNode();
                newEdge->toCity = toIndex;
                newEdge->vehicleId = p->vehicleId;
                newEdge->startTime = p->startTime;
                newEdge->endTime = p->endTime;
                newEdge->cost = p->cost;
                newEdge->vehicleType = p->vehicleType;
                newEdge->flightDays = p->flightDays;
                newEdge->model = p->model;
                newEdge->next = combinedGraph.cities[fromIndex].firstEdge;
                combinedGraph.cities[fromIndex].firstEdge = newEdge;
            }
            p = p->next;
        }
    }
    // 保存综合图
    write(combinedGraph);
}
// ========== 显示城市 ==========

void showCities(Graph &g)
{
    cout << "\n═══════════════════════════════════════════════════════════" << endl;
    cout << g.vehicleType << "图城市：" << endl;
    for (int i = 0; i < g.cityCount; i++)
    {
        cout << "  " << i << ". " << g.cities[i].cityName << endl;
    }
    cout << "═══════════════════════════════════════════════════════════" << endl;
}

// ========== 城市管理 ==========

void cityManagement()
{
    int choice;
    string name;

    cout << "\n╔════════════════════════════╗" << endl;
    cout << "║      城市管理              ║" << endl;
    cout << "╠════════════════════════════╣" << endl;
    cout << "║  1. 添加城市（火车图）     ║" << endl;
    cout << "║  2. 添加城市（飞机图）     ║" << endl;
    cout << "║  3. 删除城市（火车图）     ║" << endl;
    cout << "║  4. 删除城市（飞机图）     ║" << endl;
    cout << "║  0. 返回                   ║" << endl;
    cout << "╚════════════════════════════╝" << endl;
    cout << "请选择：";
    cin >> choice;

    if (choice == 0)
        return;

    switch (choice)
    {
    case 1:
        cout << "请输入城市名称（输入0返回可返回主菜单）：";
        cin >> name;
        if (name == "0")
            return;
        addCity(trainGraph, name);
        break;
    case 2:
        cout << "请输入城市名称（输入0返回可返回主菜单）：";
        cin >> name;
        if (name == "0")
            return;
        addCity(planeGraph, name);
        break;
    case 3:
        cout << "请输入要删除的城市名称（输入0返回可返回主菜单）：";
        cin >> name;
        if (name == "0")
            return;
        deleteCity(&trainGraph, name);
        break;
    case 4:
        cout << "请输入要删除的城市名称（输入0返回可返回主菜单）：";
        cin >> name;
        if (name == "0")
            return;
        deleteCity(&planeGraph, name);
        break;
    }
}

// ========== 班次管理 ==========

void scheduleManagement()
{
    int choice;
    string id, from, to, start, end, flightDays, model;
    int cost;

    cout << "\n╔════════════════════════════╗" << endl;
    cout << "║      班次管理              ║" << endl;
    cout << "╠════════════════════════════╣" << endl;
    cout << "║  1. 添加火车班次           ║" << endl;
    cout << "║  2. 添加航班               ║" << endl;
    cout << "║  3. 删除火车班次           ║" << endl;
    cout << "║  4. 删除航班               ║" << endl;
    cout << "║  0. 返回                   ║" << endl;
    cout << "╚════════════════════════════╝" << endl;
    cout << "请选择：";
    cin >> choice;

    if (choice == 0)
        return;

    switch (choice)
    {
    case 1:
        cout << "班次号（输入0返回可返回主菜单）：";
        cin >> id;
        if (id == "0")
            return;
        cout << "起点站（输入0返回可返回主菜单）：";
        cin >> from;
        if (from == "0")
            return;
        cout << "终点站（输入0返回可返回主菜单）：";
        cin >> to;
        if (to == "0")
            return;
        cout << "出发时间（HH:MM，输入0返回可返回主菜单）：";
        cin >> start;
        if (start == "0")
            return;
        cout << "到达时间（HH:MM，输入0返回可返回主菜单）：";
        cin >> end;
        if (end == "0")
            return;
        cout << "票价（输入0返回可返回主菜单）：";
        cin >> cost;
        if (cost == 0)
            return;
        addEdge(&trainGraph, from, to, id, parseTime(start), parseTime(end), cost, "火车", "-", "-");
        break;
    case 2:
        cout << "航班号（输入0返回可返回主菜单）：";
        cin >> id;
        if (id == "0")
            return;
        cout << "起点站（输入0返回可返回主菜单）：";
        cin >> from;
        if (from == "0")
            return;
        cout << "终点站（输入0返回可返回主菜单）：";
        cin >> to;
        if (to == "0")
            return;
        cout << "出发时间（HH:MM，输入0返回可返回主菜单）：";
        cin >> start;
        if (start == "0")
            return;
        cout << "到达时间（HH:MM，输入0返回可返回主菜单）：";
        cin >> end;
        if (end == "0")
            return;
        cout << "票价：";
        cin >> cost;
        if (cost == 0)
            return;
        cout << "航班期（如：每天）：";
        cin >> flightDays;
        if (flightDays == "0")
            return;
        cout << "机型：";
        cin >> model;
        if (model == "0")
            return;
        addEdge(&planeGraph, from, to, id, parseTime(start), parseTime(end), cost, "飞机", flightDays, model);
        break;
    case 3:
        cout << "请输入要删除的火车班次号（输入0返回可返回主菜单）：";
        cin >> id;
        if (id == "0")
            return;
        deleteEdge(&trainGraph, id);
        break;
    case 4:
        cout << "请输入要删除的航班号（输入0返回可返回主菜单）：";
        cin >> id;
        if (id == "0")
            return;
        deleteEdge(&planeGraph, id);
        break;
    }
}

// ========== 主菜单 ==========
void printStr()
{
    int space = MAX_LEN;
    for (int i = 0; i < space; i++)
        cout << "=";
}

void showMenu()
{
    printf("\n");
    printf("╔");
    printStr();
    printf("╗\n");
    printf("║%-80s║\n", "                             全国交通咨询模拟系统");
    printf("╠");
    printStr();
    printf("╣\n");
    printf("║%-78s  ║\n", "  1. 最快到达咨询");
    printf("║%-78s  ║\n", "  2. 最省钱到达咨询");
    printf("║%-78s  ║\n", "  3. 中转次数最少咨询");
    printf("║%-78s  ║\n", "  4. 城市管理（添加/删除）");
    printf("║%-78s  ║\n", "  5. 班次管理（添加/删除）");
    printf("║%-78s  ║\n", "  6. 显示火车图所有城市");
    printf("║%-78s  ║\n", "  7. 显示飞机图所有城市 ");
    printf("║%-78s  ║\n", "  8. 显示所有火车路线");
    printf("║%-78s  ║\n", "  9. 显示所有飞机航班");
    printf("║%-78s  ║\n", "  0. 退出系统 ");
    printf("╚");
    printStr();
    printf("╝\n");
    printf("请输入您想要使用的功能序号（数字）：");
}

// ========== 主函数 ==========
void Continue()
{
    cout << "\n若需继续查询，请按任意键返回主菜单.....";
    _getch();
}

void executeQuery(int queryType, const string &start, const string &end, Graph *g, const string &modeName)
{
    int startIndex = findVertex(g, start);
    int endIndex = findVertex(g, end);

    if (startIndex == -1 && endIndex == -1)
    {
        cout << "当前" << g->vehicleType << "交通图中不存在城市" << "【" << start << "】和【" << end << "】" << endl;
        return;
    }
    else if (startIndex == -1)
    {
        cout << "当前" << g->vehicleType << "交通图中不存在城市" << "【" << start << "】" << endl;
        return;
    }
    else if (endIndex == -1)
    {
        cout << "当前" << g->vehicleType << "交通图中不存在城市" << "【" << end << "】" << endl;
        return;
    }

    if (queryType == 1)
    {
        fastestPath(g, startIndex, endIndex);
    }
    else if (queryType == 2)
    {
        cheapestPath(g, startIndex, endIndex);
    }
    else if (queryType == 3)
    {
        minTransferPath(g, startIndex, endIndex);
    }
}

int main()
{

    trainGraph.vehicleType = "火车";
    planeGraph.vehicleType = "飞机";
    combinedGraph.vehicleType = "综合";

    cout << "———————————————————数据加载———————————————————" << endl;
    runingData(trainGraph);
    runingData(planeGraph);

    cout << "已读取文件内保存的城市、班次原有数据。" << endl;
    cout << "\n欢迎使用全国交通咨询模拟系统！" << endl;
    cout << "\n尊敬的用户，当前系统已导入历史线路信息，您可自行上拉或通过菜单查看，若现有" << endl;
    cout << "数据不能满足您的需求，可借助下列菜单4、5，自行新增城市和交通班次。" << endl;
    cout << "\n查询过程中如有输入错误，您可在任意需要输入的位置输入数字‘0’即可选择是否终止本次" << endl;
    cout << "查询并返回主菜单或退出系统。" << endl;
    cout << "\n原有数据会一直保留。" << endl;
    cout << "\n祝您使用愉快。" << endl;

    int choice;
    string start, end, vType;
    int continueFlag = 1; // 控制外层循环

    while (continueFlag)
    {
        showMenu();
        cin >> choice;

        if (choice == 0)
        {
            cout << "感谢使用交通咨询系统，祝您出行顺利，再见！" << endl;
            break;
        }

        switch (choice)
        {
        case 1: // 最快到达
        case 2: // 最省钱到达
        case 3:
        { // 中转次数最少
            cout << "请输入起始站：";
            cin >> start;
            if (start == "0")
            {
                // 询问是否继续
                printf("\n是否继续查询？(y/n)：");
                char cont;
                while (true)
                {
                    cin >> cont;
                    if (cont == 'n' || cont == 'N')
                    {
                        continueFlag = 0;
                        break;
                    }
                    else if (cont == 'y' || cont == 'Y')
                    {
                        continueFlag = 1;
                        break;
                    }
                    else
                    {
                        cout << "输入错误，请重新输入（y/n）：" << endl;
                    }
                }
                break;
            }

            cout << "请输入终点站：";
            cin >> end;
            if (start == "0")
            {
                // 询问是否继续
                printf("\n是否继续查询？(y/n)：");
                char cont;
                while (true)
                {
                    cin >> cont;
                    if (cont == 'n' || cont == 'N')
                    {
                        continueFlag = 0;
                        break;
                    }
                    else if (cont == 'y' || cont == 'Y')
                    {
                        continueFlag = 1;
                        break;
                    }
                    else
                    {
                        cout << "输入错误，请重新输入（y/n）：";
                    }
                }
                break;
            }

            string queryTypeName = (choice == 1) ? "最快到达" : ((choice == 2) ? "最省钱" : "中转次数最少");

            cout << "\n";

            cout << "                 【" << queryTypeName << "】查询结果（共3种方案）" << endl;

            // 方案一：只火车
            cout << "\n";
            cout << " 【方案一】只乘坐火车" << endl;
            executeQuery(choice, start, end, &trainGraph, "火车");

            // 方案二：只飞机
            cout << "\n";
            cout << " 【方案二】只乘坐飞机" << endl;
            executeQuery(choice, start, end, &planeGraph, "飞机");

            // 方案三：综合（不限交通工具）
            cout << "\n";
            cout << " 【方案三】不限交通工具" << endl;

            // 同步综合图
            syncCombinedGraph();
            executeQuery(choice, start, end, &combinedGraph, "综合");

            Continue();
            break;
        }
        case 4: // 城市管理
            cityManagement();
            Continue();
            break;
        case 5: // 班次管理
            scheduleManagement();
            Continue();
            break;
        case 6: // 显示城市
            showCities(trainGraph);
            Continue();
            break;
        case 7:
            showCities(planeGraph);
            Continue();
            break;
        case 8: // 显示火车图
            showGraph(&trainGraph);
            Continue();
            break;
        case 9: // 显示飞机图
            showGraph(&planeGraph);
            Continue();
            break;
        default:
            cout << "【×】无效选择！" << endl;
            Continue();
        }
    }
}