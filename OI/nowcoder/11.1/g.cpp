#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll min_num = 1000000001;
ll min_numchu;
int main()
{
    ll n;
    cin >> n;
    ll a[n + 5][2];

    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2];
        if (min_num > a[i][1] + a[i][2])
        {
            min_num = a[i][1] + a[i][2];
            min_numchu = a[i][1];
        }
    }
    ll num = min_num;

    ll x = 0;
    while (num != 2147483648)
    {
        x = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (num % a[i][1] == a[i][2])
            {
                x++;
            }
        }
        if (x == n)
        {
            cout << num;
            return 0;
        }
        else
        {
            num += min_numchu;
        }
    }
}