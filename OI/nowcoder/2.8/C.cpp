#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll v[100002];
// v[n][1]入度 [2]出度
int main()
{
    ll n;
    cin >> n;
    ll x, y;
    for (int i = 1; i <= n; i++)
    {
        v[i] = 0;
    }
    for (int i = 1; i <= n-1; i++)
    {
        cin >> x >> y;
        v[x]++;
        v[y]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] >= 4)
        {
            cout << "0";
            return 0;
        }
        if (v[i] <= 2)
            ans++;
    }
    cout << ans;
}
