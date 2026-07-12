#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int n = S.size(), m = T.size();

    // dp[i][j]: 以位置 i 结尾，刚好匹配到 T 的第 j 个字符的子串数
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        char s = S[i - 1];

        // A: 新建长度为1的子串，S[i] ≠ T[1]
        if (s != T[0])
        {
            dp[i][0]++;
        }

        // B: 新建长度为1的子串，S[i] = T[1]
        if (s == T[0])
        {
            dp[i][1]++;
        }

        // C: 继承 dp[i-1][j]
        for (int j = 0; j <= m; j++)
        {
            if (j == m || s != T[j])
            { // j=m 时总是继承；j<m 时需要 s ≠ T[j+1]
                dp[i][j] += dp[i - 1][j];
            }
        }

        // D: 从 dp[i-1][j-1] 转移
        for (int j = 1; j <= m; j++)
        {
            if (s == T[j - 1])
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }

        // 累加答案：所有 j < m 的状态
        for (int j = 0; j < m; j++)
        {
            ans += dp[i][j];
        }
    }

    for (auto i : dp)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << ans << endl;

    return 0;
}