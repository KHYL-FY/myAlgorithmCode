#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
string a;
bool ifans = false;
bool prim(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void dfs(int p)
{

    if (ifans || p > (int)a.length())
        return;
    if (p >= (int)a.length() )
    {
        int num = stoi(a);
        if (prim(num))
        {
            cout << num << endl;
            ifans = true;
            return;
        }
    }
    if (a[p] >= '0' && a[p] <= '9')
        dfs(p + 1);

    if (a[p] == '*')
    {
        for (int i = 0; i <= 9; i++)
        {
            a[p] = (char)(i + '0');
           // cout << a << endl;
            dfs(p + 1);
            
            a[p] = '*';

        }
    }

    return;
}
int main()
{
    int T;

    cin >> T;

    while (T--)
    {
        cin >> a;
        ifans = false;
        dfs(0);
        if (!ifans)
            cout << -1 << endl;
    }
}