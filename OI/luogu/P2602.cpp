 #include <iostream>

using namespace std;

typedef long long ll;

const ll M = 12;
ll l, r;

ll ten[M], dp[M];
ll cnta[M], cntb[M];
ll num[M];
void init()
{

    ten[0] = 1;
    for (int i = 1; i <= M; i++)
    {
        dp[i] = dp[i - 1] * 10 + ten[i - 1];
        ten[i] = ten[i - 1] * 10;
    }

    // for (int i = 1; i <= M; i++)
    // {
    //     cout << dp[i] << " ";
    // }
}
void solve(ll x, ll cnt[])
{

    ll len = 0;
    do
    {
        num[++len] = x % 10;
        x /= 10;
    } while (x);

    // for (int i = 1; i <= len; i++)
    // {
    //     cout << num[i] << " ";
    // }

    for (int i = len; i >= 1; i--)
    {
        for (int j = 0; j <= 9; j++)
        {
            // cout << num[i] * dp[i - 1] << endl;
            cnt[j] += (num[i] * dp[i - 1]);
        }

        for (int j = 0; j < num[i]; j++)
            cnt[j] += ten[i - 1];

        ll num2 = 0;
        for (int j = i - 1; j >= 1; j--)
            num2 = num2 * 10 + num[j];
        cnt[num[i]] += num2 + 1;
        cnt[0] -= ten[i - 1];
    }
}
int main()
{
    init();
    cin >> l >> r;

    solve(l - 1, cnta);
    solve(r, cntb);

    for (int i = 0; i <= 9; i++)
        cout << cntb[i] - cnta[i] << " ";
}