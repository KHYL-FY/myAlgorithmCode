#include <bits/stdc++.h>

using namespace std;

int main()
{
    int money, kongPing, gaiZi, jiaGe;
    cin >> money >> kongPing >> gaiZi >> jiaGe;

    int jiuPing = 0;
    if (money > 0)
    {
        jiuPing += money / jiaGe;
    }

    gaiZi += jiuPing;
    kongPing += jiuPing;

    while (gaiZi >= 4 || kongPing >= 2)
    {
        if (gaiZi >= 4)
        {
            gaiZi -= 4;
            jiuPing++;
            gaiZi++;
            kongPing++;
        }
        if (kongPing >= 2)
        {
            kongPing -= 2;
            jiuPing++;
            gaiZi++;
            kongPing++;
        }
    }

    cout << jiuPing;
}