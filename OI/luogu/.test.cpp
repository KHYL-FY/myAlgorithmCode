#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
int nx = 0, ny = 0;
int dirx[10] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int diry[10] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
char mapp[101][101];
void dfs(int x, int y)
{
    mapp[x][y] = '.';
    for (int i = 1; i <= 8; i++)
    {
        nx = x + dirx[i];
        ny = y + diry[i];
        if (nx > n || nx < 1 || ny < 1 || ny > m || mapp[nx][ny] == '.')
            continue;
        else
            dfs(nx, ny);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mapp[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mapp[i][j] == 'W')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}