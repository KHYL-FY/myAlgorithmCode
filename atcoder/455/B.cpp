#include <bits/stdc++.h>

using namespace std;
char a[20][20];
int n, m;
bool iflegal(int x1, int y1, int x2, int y2)
{
    int i = x1, j = y1, x = x2, y = y2;

    for (i = x1, x = x2; i <= x2; i++, x--)
    {
        for (j = y1, y = y2; j <= y2; j++, y--)
        {
            if (a[i][j] != a[x][y])
            {
                return false;
            }
        }
    }
    // do
    // {
    //     do
    //     {
    //         if (a[i][j] != a[x][y])
    //         {
    //             return false;
    //         }
    //         j++, y--;
    //     } while (j <= y);
    //     i++;
    //     x--;
    // } while (i <= x);

    return true;
}
int main()
{

    cin >> n >> m;
    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // iflegal(2, 1, 3, 2);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int x = i; x <= n; x++)
            {
                for (int y = j; y <= m; y++)
                {
                    if (iflegal(i, j, x, y))

                    {
                        ans++;
                        // cout << i << j << x << y << endl;
                    }
                }
            }
        }
    }

    cout << ans;
}