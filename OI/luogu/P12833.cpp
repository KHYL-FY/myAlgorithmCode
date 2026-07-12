#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll dp[100000005][2];
void solve()
{
    ll n;
    cin >> n;
    string a, b, c;
    a = "0";
    b = "1";

    n -= 2;
    ll oneCount = 0, ans = 0;
    while (n--)
    {
        c = a + b;
        a = b;
        b = c;
    }
    ll len = c.length();
    c = " " + c;
    for (int i = 1; i <= len; i++)
    {
        if (c[i] == '0')
        {
            dp[i][1] = (dp[i][1] + (dp[i - 1][1] * dp[i - 1][0]) % mod) % mod;
            dp[i][0] = dp[i - 1][0];
        }
        else
        {
            dp[i][1] = dp[i - 1][0];
            dp[i][0] = dp[i - 1][0] + 1;
        }
    }
    cout << dp[len][1] << endl;
    // cout << c;

    return;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}