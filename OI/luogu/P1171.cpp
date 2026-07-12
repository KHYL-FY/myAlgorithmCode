#include <iostream>
#include <cstring>
// 记忆化搜索dfs(递归)
using namespace std;

int n;
const int M = 21;
int graph[M][M];
// map<pair<int, int>, int> dp;
int dp[(1 << 20) + 5][25];

int f(int status, int p)
{

    if (status == (1 << n) - 1)
        return graph[p][0];

    if (dp[status][p] != -1)
        return dp[status][p];

    int ans = 0x7ffffff;

    // 只枚举未访问的城市，用位运算跳过已访问的
    int unvisited = ((1 << n) - 1) ^ status;
    while (unvisited)
    {
        int i = __builtin_ctz(unvisited); // 取最低位1的位置
        ans = min(ans, graph[p][i] + f(status | (1 << i), i));
        unvisited &= unvisited - 1; // 清除最低位的1
    }

    dp[status][p] = ans;
    // cout << ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << f(1, 0);
}