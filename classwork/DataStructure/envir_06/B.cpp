#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

#include "Graph_AL.h"

using namespace std;

//邻接表
int main()
{
    Graph_AL a;
    int vex, edge;
    cin >> vex >> edge;
    a.creatUDN(vex, edge);
    a.outUDN();
}