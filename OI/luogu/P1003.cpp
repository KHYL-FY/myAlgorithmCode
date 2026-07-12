#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n + 5][4];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    int x, y;
    int ans = 0;
    cin >> x >> y;

    for (int i = 1; i <= n; i++)
    {
        // if (a[i][2] == 0 || a[i][3] == 0)
        //     continue;
        if (x >= a[i][0] && x <= a[i][0] + a[i][2] - 1)
        {
            if (y >= a[i][1] && y <= a[i][1] + a[i][3] - 1)
                ans = i;
        }
    }
    if (!ans)
        cout << -1;
    else
        cout << ans;
}