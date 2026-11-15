// P3958 奶酪 暴力（对拍用）：建图后从接地球 BFS/DFS 找能不能到顶。
// 编译：g++ -O2 -o p3958_brute.exe p3958_brute.cpp
// 刻意和正解用不同的写法（暴力 BFS + __int128 判距离），这样两边不会错在一处。
#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int main()
{
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        long long n, h, r;
        cin >> n >> h >> r;
        vector<array<long long, 3>> p(n);
        for (auto &a : p)
            cin >> a[0] >> a[1] >> a[2];

        vector<int> vis(n, 0);
        queue<int> q;
        for (int i = 0; i < (int)n; i++)
            if ((__int128)p[i][2] - r <= 0)          // 接地
                vis[i] = 1, q.push(i);

        bool ok = false;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if ((__int128)p[u][2] + r >= h)          // 到顶
            {
                ok = true;
                break;
            }
            for (int v = 0; v < (int)n; v++)
            {
                if (vis[v])
                    continue;
                __int128 dx = p[u][0] - p[v][0];
                __int128 dy = p[u][1] - p[v][1];
                __int128 dz = p[u][2] - p[v][2];
                if (dx * dx + dy * dy + dz * dz <= (__int128)4 * r * r)
                    vis[v] = 1, q.push(v);
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
