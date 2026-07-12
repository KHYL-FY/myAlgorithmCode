#include <iostream>

using namespace std;

typedef long long ll;
ll n, mul, add;
char opt[16];
ll num[20], f[20][20];
ll ans = 0;
ll cal(ll x, ll y, ll t)
{
    return (opt[t] == '*' ? x * y : x + y);
}
void dp()
{
    for (ll i = 1; i <= 18; i++)
    {
        for (ll j = 1; j <= 18; j++)
        {
            f[i][j] = 0;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        f[i][i] = num[i];
    }

    for (ll l = 1; l < n; l++)
    {
        for (ll i = 1; i <= n - l; i++)
        {
            ll j = i + l;

            for (ll k = i; k < j; k++)
            {
                f[i][j] = max(f[i][j], cal(f[i][k], f[k + 1][j], k));
            }
        }
    }

    // for (ll i = 1; i < n; i++)
    // {
    //     cout << num[i] << opt[i];
    // }
    // cout << num[n] << " = " << f[1][n] << endl;
    ans = max(f[1][n], ans);
}
void dfs(ll m, ll a, ll pos)
{
    // if (m > mul || a > mul)
    //     return;
    // cout << 1;
    if (pos == n)
    {
        // for (ll i = 1; i < n; i++)
        // {
        //     cout << num[i] << opt[i];
        // }
        // cout << num[n] << endl;
        dp();
        // cout << 1;
        return;
    }

    if (m < mul)
    {
        opt[pos] = '*';
        dfs(m + 1, a, pos + 1);
    }
    if (a < add)
    {
        opt[pos] = '+';
        dfs(m, a + 1, pos + 1);
    }

    return;
}
int main()
{
    cin >> n >> mul;
    add = n - mul - 1;

    for (ll i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    dfs(0, 0, 1);
    // dp();

    cout << ans;
}