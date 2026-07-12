#include <iostream>
#include <cstring>
//递推
using namespace std;

int n;
const int INF = 0x3f3f3f3f;
int graph[21][21];
int dp[(1 << 20) + 5][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0; // 起点：只访问了城市0，停在城市0

    // 从小到大枚举 mask，用"推"的方式转移
    for (int mask = 1; mask < (1 << n); mask++)
    {
        if (!(mask & 1))
            continue; // 必须包含城市0，否则无意义

        // 位运算枚举 mask 中所有城市 p
        int cities = mask;
        while (cities)
        {
            int p = __builtin_ctz(cities);
            cities &= cities - 1;

            if (dp[mask][p] == INF)
                continue; // 不可达，跳过

            // 枚举所有未访问的城市作为下一步
            int unvisited = ((1 << n) - 1) ^ mask;
            while (unvisited)
            {
                int next = __builtin_ctz(unvisited);
                unvisited &= unvisited - 1;

                int nmask = mask | (1 << next);
                int cost = dp[mask][p] + graph[p][next];
                if (cost < dp[nmask][next])
                    dp[nmask][next] = cost;
            }
        }
    }

    // 所有城市都访问完，加上回到城市0的代价
    int full = (1 << n) - 1;
    int ans = INF;
    for (int p = 0; p < n; p++)
        ans = min(ans, dp[full][p] + graph[p][0]);

    cout << ans;
    return 0;
}
