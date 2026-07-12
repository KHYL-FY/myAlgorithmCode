#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const ll M = 20;

ll num[M + 5], dp[M + 5][M + 5][M + 5];
ll len = 0;

void init(ll n)
{
    len = 0;
    memset(dp, -1, sizeof(dp));
    // for (int i = 0; i <= M + 4; i++)
    // {
    //     for (int j = 0; j <= M + 4; j++)
    //     {
    //         for (int x = 0; x <= M + 4; x++)
    //         {
    //             dp[i][j][x] = -1;
    //         }
    //     }
    // }
    do
    {
        num[++len] = n % 10;
        n /= 10;
    } while (n);

    // for (int i = len; i >= 1; i--)
    // {
    //     cout << num[i] << " ";
    // }
}

ll dfs(ll pre, ll p, bool free)
{
    if (p == 0)
    {
        return 1;
    }
    ll ans = 0;
    if (dp[pre][p][free] != -1)
    {
        return dp[pre][p][free];
    }

    if (free)
    {
        // ans += dfs(11, p - 1, true);
        if (pre == 11)
            ans += dfs(11, p - 1, true);
        if (pre != 11 && pre >= 2)
        {
            ans += dfs(0, p - 1, true);
        }

        for (ll i = 1; i <= 9; i++)
        {
            if (i - pre >= 2 || pre - i >= 2)
            {
                ans += dfs(i, p - 1, true);
            }
        }
    }
    else
    {
        if (pre != 11 && pre >= 2)
        {
            if (num[p] == 0)
                ans += dfs(0, p - 1, false);
            else
                ans += dfs(0, p - 1, true);
        }

        for (ll i = 1; i < num[p]; i++)
        {
            if (i - pre >= 2 || pre - i >= 2)
            {
                ans += dfs(i, p - 1, true);
            }
        }

        if (num[p] != 0 || pre == 11 || pre < 2)
        {
            if (num[p] - pre >= 2 || pre - num[p] >= 2)
            {
                ans += dfs(num[p], p - 1, false);
            }
        }

        if (pre == 11)
        {
            if (num[p] == 0)
                ans += dfs(11, p - 1, false);  
            else
                ans += dfs(11, p - 1, true);   
        }
    }

    dp[pre][p][free] = ans;
    return ans;
}

ll solve(ll n)
{
    init(n);
    if (len == 1)
        return n + 1;

    return dfs(11, len, false);
}
int main()
{
    ll l, r;

    cin >> l >> r;

    cout << solve(r) - solve(l - 1);
}