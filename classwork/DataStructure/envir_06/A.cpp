#include <iostream>
#include <map>
#include <iomanip>

#include "Graph_AM.h"

using namespace std;

//邻接矩阵
int main()
{
    Graph_AM a;
    int vex, edge;
    cin >> vex >> edge;
    a.creatUDN(vex, edge);
    a.outUDN();
}