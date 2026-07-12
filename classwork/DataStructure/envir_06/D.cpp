#include <iostream>
#include "Graph_AL.h"

using namespace std;
//邻接表dfs
class dfs_graph : public Graph_AL
{
private:
    bool visit[LVNum];

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
                for (auto j : edges[i])
                {
                    if (!visit[j])
                    {
                        _dfs_graph(j);
                    }
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