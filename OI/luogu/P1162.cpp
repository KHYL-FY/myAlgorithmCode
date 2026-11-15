#include <iostream>
using namespace std;
int n;
int m[32][32];
void dfs(int x, int y)
{
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || m[x][y] == 1 || m[x][y] == 3)
        return;
    m[x][y] = 3;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main()
{
    // freopen("2.in","r",stdin);
    // freopen("1.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j] == 0)
                m[i][j] = 2;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j] == 3)
                m[i][j] = 0;
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}