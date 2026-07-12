#include <iostream>

using namespace std;
typedef long long ll;

ll n;
ll stn[205];
ll f1[205][205];
ll f2[205][205];
ll sum[205];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = 1; j <= n * 2; j++)
        {
            f1[i][j] = 0x7fffffffff;
            f2[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> stn[i];
        stn[n + i] = stn[i];

        f1[i][i] = f1[n + i][n + i] = 0;
        f2[i][i] = f2[n + i][n + i] = 0;
        sum[i] = sum[i - 1] + stn[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + stn[i];

    for (int l = 1; l < 2 * n; l++)
    {
        for (int i = 1; i < 2 * n - l; i++)
        {
            int j = i + l;

            for (int k = i; k < j; k++)
            {
                f1[i][j] = min(f1[i][j], f1[i][k] + f1[k + 1][j] + sum[j] - sum[i - 1]);
                f2[i][j] = max(f2[i][j], f2[i][k] + f2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    ll ansmin = 0x7ffffffff, ansmax = -1;

    for (int i = 0; i <= n; i++)
    {
        ansmin = min(f1[i + 1][n + i], ansmin);
        ansmax = max(f2[i + 1][n + i], ansmax);
    }
    cout << ansmin << endl
         << ansmax;
}