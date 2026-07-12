#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

ll n;
ll s[15], b[15];
ll ans = 1e12;

void dfs(ll sumS, ll sumB, ll i)
{
    if (i > n)
    {
        if (sumS == 1 && sumB == 0)
            return;
        ans = min(ans, abs(sumS - sumB));
        return;
    }
    dfs(sumS * s[i], sumB + b[i], i + 1);
    dfs(sumS, sumB, i + 1);
}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> s[i] >> b[i];
    }
    dfs(1, 0, 1);
    cout << ans;
}