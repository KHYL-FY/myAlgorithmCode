#include <iostream>

using namespace std;
typedef long long ll;

const ll M = 1e5 + 5;
const ll mod = 1e9 + 7;

ll dp[M][3];
void init()
{

    dp[1][0] = 1, dp[1][1] = 0, dp[1][2] = 0;
    dp[2][0] = 0, dp[2][1] = 1, dp[2][2] = 0;

    for (ll i = 3; i <= M - 5; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 2][0]) % mod;
        dp[i][1] = (dp[i - 1][1] + dp[i - 2][1]) % mod;
        dp[i][2] = ((dp[i - 1][2] + dp[i - 2][2]) % mod + (dp[i - 1][0] * dp[i - 2][1]) % mod) % mod;
    }
}
int main()
{
    ll n, t;
    cin >> t;

    init();
    while (t--)
    {
        cin >> n;
        cout << dp[n][2] % mod << endl;
    }
}