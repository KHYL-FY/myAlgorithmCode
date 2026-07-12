//设逆时针为正方向(也就是1),顺时针为负方向(就是-1) 朝里的右侧为正方向 左侧为负方向
//那么对于朝外的人来说只要将他的方向乘上-1即可
//使用指针一步步跟着走就可以了
//处理好左边界和右边界答案就可以出来了

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct people
{
    int dir;
    string name;
};
people a[100002];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].dir >> a[i].name;
        if (a[i].dir == 1)
            a[i].dir = -1;
        if (a[i].dir == 0)
            a[i].dir = 1;
    }

    int pointer = 1;
    int d, step;
    for (int i = 1; i <= m; i++)
    {
        cin >> d >> step;
        if (d == 0)
            d = -1;

        pointer += step * d * a[pointer].dir;

        if (pointer >= n)
        {
            pointer %= n;
        }

        if (pointer <= 0)
        {
            pointer = abs(pointer);
            pointer %= n;
            pointer = n - pointer;
        }
    }
    cout << a[pointer].name;
}