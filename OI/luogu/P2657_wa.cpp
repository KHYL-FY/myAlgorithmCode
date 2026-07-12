#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
const ll M = 15;
ll dp[M], pow7[M];
ll num[M];
ll cnta = 0, cntb = 0;

void init()
{
    dp[0] = 0;
    pow7[0] = 1;

    for (int i = 1; i < M; i++)
    {
        dp[i] = dp[i - 1] + pow7[i - 1] * 9;
        pow7[i] = pow7[i - 1] * 7;
    }
}

void solve(ll x, ll &cnt)
{
    int len = 0;
    ll xcopy = x;
    // cout << xcopy;
    do
    {
        num[++len] = x % 10;
        x /= 10;
    } while (x);
    if (len == 1)
    {
        cnt = xcopy;
        // cout << xcopy;
        return;
    }

    cnt += dp[len - 1];

    cnt += (num[len] - 1) * pow7[len - 1];
    // cout << (num[len] - 1) * pow7[len - 1] << endl;
    // cout << cnt;
    for (int i = len; i >= 1; i--)
    {
        for (int j = 0; j < num[i - 1]; j++)
        {
            if (abs(num[i] - j) >= 2)
            {

                cnt += pow7[i - 2];
                cout << cnt << endl;
            }
        }

        if (abs(num[i] - num[i - 1]) < 2)
            break;
    }
    cout << cnt;
}
int main()
{
    init();
    ll a, b;
    cin >> a >> b;

    solve(a - 1, cnta);
    // solve(b, cntb);

    // cout << cntb << " " << cnta;
} // 72