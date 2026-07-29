#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;
const int MAXN = 105;

ll memo[MAXN][MAXN][MAXN];
int N, M;

// f(n, m, k): 还剩 n 个店、m 朵花、k 斗酒的方案数
ll dfs(int n, int m, int k)
{
    // 边界：酒为负、酒比剩余花多、酒等于花数但还有店
    if (k < 0 || k > m || (k == m && n != 0))
        return 0;
    // 记忆化
    if (memo[n][m][k] != -1)
        return memo[n][m][k];

    ll ans = 0;

    // 遇店：酒加倍
    if (n > 0 && k * 2 <= m)
    {
        ans = (ans + dfs(n - 1, m, k * 2)) % mod;
    }

    // 遇花：喝一斗
    if (m > 0 && k > 0)
    {
        if (n == 0 && m == 1 && k == 1)
        {
            ans = (ans + 1) % mod;
        }
        else
        {
            ans = (ans + dfs(n, m - 1, k - 1)) % mod;
        }
    }

    return memo[n][m][k] = ans;
}

int main()
{
    cin >> N >> M;
    memset(memo, -1, sizeof(memo));
    cout << dfs(N, M, 2) << endl;
    return 0;
}