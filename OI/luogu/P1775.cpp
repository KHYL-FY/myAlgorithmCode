#include <iostream>

using namespace std;
typedef long long ll;

ll n;
ll stn[305];
ll f[305][305];
ll sum[305];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = 0x7ffffffffffff;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> stn[i];
        f[i][i] = 0;
        sum[i] += sum[i - 1] + stn[i];
    }

    for (int l = 1; l < n; l++)
    {
        for (int i = 1; i <= n - l; i++)
        {
            int j = i + l;

            for (int k = i; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    cout << f[1][n];
}