// 小明的游戏6

#include <iostream>
#define ll unsigned long long
using namespace std;

int main()
{
    ll n, m;
    ll t;
    cin >> t;

    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> m;
        if (n <= m)
        {
            cout << "NO" << endl;
            continue;
        }
        if (n % (m + 1) == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}