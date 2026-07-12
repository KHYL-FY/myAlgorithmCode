
// 图的邻接表存储
/*
edge
    target 终点编号
    weight 权值
    treansName 其他信息 此处为 列车/飞机 班号


void addWeight(const int &u, const edge &node)
添加一条有权边 u起点  node(target 终点, weight 权值)

void deleteWeight(const int &u, const edge &node)
删除一条有权边 u起点  node(target 终点, weight 权值)

*/

#include <iostream>
#include <algorithm>
#include <vector>

// #define DEBUG

struct edge
{
    int start;
    int target;
    int weight;
    std::string otherInfo;

    edge(int u, int v, int w, std::string c) : start(u), target(v), weight(w), otherInfo(c) {}

    bool operator==(const edge &a) const
    {
        return target == a.target && weight == a.weight && otherInfo == a.otherInfo && start == a.start;
    }
};

class Graph_AdjList
{
    const static int VERTEX_MAX = 501;

public:
    std::vector<edge> graph[VERTEX_MAX];

protected:

    void add_weight_edge(const int &u, const edge &node)
    {
        graph[u].push_back(node);
        return;
    }
    void delete_weigth_edge(const int &u, const edge &node)
    {
        auto itDelete = std::find(graph[u].begin(), graph[u].end(), node);
        if (itDelete != graph[u].end())
        {
            graph[u].erase(itDelete);
        }
        return;
    }

public:
    void addWeight(const int &u, const edge &node)
    {
        add_weight_edge(u, node);
        return;
    }
    void deleteWeight(const int &u, const edge &node)
    {
        delete_weigth_edge(u, node);
        return;
    }
#ifdef DEBUG
    void testout()
    {
        for (int i = 1; i <= 20; i++)
        {
            if (graph[i].empty())
            {
                std::cout << i << "->NULL" << std::endl;
                continue;
            }
            for (auto j = graph[i].begin(); j != graph[i].end(); j++)
            {
                std::cout << i << "->" << (*j).target << "(" << (*j).weight << ") ";
            }
            std::cout << std::endl;
        }
    }
#endif
};