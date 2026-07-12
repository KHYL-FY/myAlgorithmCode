#include <iostream>
#include <map>
#include <iomanip>
#include <vector>


using namespace std;


class Graph_AL
{
#define LVNum 100
#define OK 0
#define ERROR -1

protected:
    typedef char vertexType;
    typedef int edgeType;

    vertexType vexs[LVNum + 1];
    vector<int> edges[LVNum];

    int vexNum = -1, edgeNum = -1;
    map<char, int> vex_to_num;

    void _createUDN_NUM(int in_vexNum, int in_edgeNum)
    {
        vexNum = in_vexNum;
        edgeNum = in_edgeNum;
        return;
    }
    void _createUDN_VEX()
    {
        for (int i = 1; i <= vexNum; i++)
        {
            cin >> vexs[i];
            vex_to_num[vexs[i]] = i;
        }

        char v1, v2;
        for (int i = 1; i <= edgeNum; i++)
        {
            cin >> v1 >> v2;
            edges[vex_to_num[v1]].push_back(vex_to_num[v2]);
            edges[vex_to_num[v2]].push_back(vex_to_num[v1]);
        }

        return;
    }
    void _out_UDN()
    {
        for (int i = 1; i <= vexNum; i++)
        {
            cout << i << "|" << vexs[i];
            for (auto j : edges[i])
            {
                cout << "->" << j;
            }
            cout << endl;
        }
    }

public:
    void creatUDN(int in_vexNum, int in_edgeNum)
    {
        _createUDN_NUM(in_vexNum, in_edgeNum);
        _createUDN_VEX();
    }
    void outUDN()
    {
        _out_UDN();
    }
};
