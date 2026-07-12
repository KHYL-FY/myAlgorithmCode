#include <bits/stdc++.h>

using namespace std;

char a[505][505];

int ans = 0;
int n, m;

void dfs(int x, int y)
{
    if (x < 0 || x > n + 1 || y < 0 || y > m + 1)
    {
        return;
    }
    if (a[x][y] == '*')
    {
        return;
    }
    if (a[x][y] == '1')
    {
        return;
    }

    a[x][y] = '1';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main()
{
    memset(a, 0, sizeof(a));

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(0, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '0')
            {
                ans++;
            }
        }
    }

    
    cout << ans;
}
