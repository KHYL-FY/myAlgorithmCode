#include <iostream>
#include "Graph_AM.h"

using namespace std;
// 邻接矩阵dfs
class dfs_graph : public Graph_AM
{
private:
    bool visit[MVNum];

    void _dfs_graph(int ver)
    {
        if (visit[ver])
            return;
        else
        {
            visit[ver] = true;
            cout << vexs[ver] << " ";
            for (int i = 1; i <= vexNum; i++)
            {
                if (edges[ver][i] != -1 && !visit[i])
                {
                    _dfs_graph(i);
                }
            }
        }

        return;
    }
    void init_visit()
    {
        for (int i = 1; i <= vexNum; i++)
        {
            visit[i] = false;
        }
    }

public:
    void dfs_Graph()
    {
        init_visit();
        _dfs_graph(1);
        cout << endl;
    }
};

int main()
{
    dfs_graph a;
    int vex, edge;
    cin >> vex >> edge;
    a.creatUDN(vex, edge);

    cout << endl;
    a.outUDN();
    cout << endl;

    a.dfs_Graph();
}