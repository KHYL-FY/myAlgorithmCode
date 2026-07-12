#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

class Graph_AM
{
#define MVNum 100
#define OK 0
#define ERROR -1

protected:
    typedef char vertexType;
    typedef int edgeType;

    vertexType vexs[MVNum + 1];
    edgeType edges[MVNum + 1][MVNum + 1];
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

        for (int i = 1; i <= vexNum; i++)
        {
            for (int j = 1; j <= vexNum; j++)
            {
                edges[i][j] = -1;
            }
        }

        char v1, v2;
        int w;
        for (int i = 1; i <= edgeNum; i++)
        {
            cin >> v1 >> v2 >> w;

            edges[vex_to_num[v1]][vex_to_num[v2]] = w;
            edges[vex_to_num[v2]][vex_to_num[v1]] = w;
        }

        return;
    }
    void _out_UDN()
    {
        cout << left;
        for (int i = 1; i <= vexNum; i++)
        {
            for (int j = 1; j <= vexNum; j++)
            {
                if (edges[i][j] == -1)
                    cout << setw(8) << "∞";
                else
                    cout << setw(8) << edges[i][j];
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
