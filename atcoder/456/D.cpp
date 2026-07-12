#include <iostream>

using namespace std;

typedef long long ll;
ll dp[1000005][4];
int main()
{
    const ll mod = 998244353;

    string a;
    cin >> a;
    ll len = a.length();
    a = " " + a;
    for (ll i = 1; i <= len; i++)
    {
        switch (a[i])
        {
        case 'a':
            dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + 1;
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = dp[i - 1][3];
            dp[i][1] %= mod;
            dp[i][2] %= mod;
            dp[i][3] %= mod;
            break;
        case 'b':
            dp[i][2] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + 1;
            dp[i][1] = dp[i - 1][1];
            dp[i][3] = dp[i - 1][3];
            dp[i][1] %= mod;
            dp[i][2] %= mod;
            dp[i][3] %= mod;
            break;
        case 'c':
            dp[i][3] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + 1;
            dp[i][2] = dp[i - 1][2];
            dp[i][1] = dp[i - 1][1];
            dp[i][1] %= mod;
            dp[i][2] %= mod;
            dp[i][3] %= mod;
            break;
        }
    }
    ll ans = (dp[len][1] + dp[len][2] + dp[len][3]) % mod;
    cout << ans;
}