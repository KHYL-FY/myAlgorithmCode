#include <bits/stdc++.h>

using namespace std;
char mapp[50][50];
int n;
void dfs(int x, int y)
{
    if (x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1)
    {
        if (mapp[x][y] == '#' || mapp[x][y] == 'a')
        {
            return;
        }
        if (mapp[x][y] != '#')
            mapp[x][y] = 'a';

        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
    }

    return;
}
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mapp[i][j];
        }
    }

    dfs(0, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mapp[i][j] == '.')
            {
                mapp[i][j] = 'p';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mapp[i][j] == 'a')
            {
                mapp[i][j] = '.';
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mapp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}