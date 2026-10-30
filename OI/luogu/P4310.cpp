#include <iostream>
#include <vector>

using namespace std;
int main()
{
    typedef long long ll;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> dp(31, 0);
    ll num, maxx = -1, b = 1, t;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        maxx = -1;
        t = num;
        b = 1;

        while (t)
        {
            if ((t & 1) == 1)
                maxx = max(maxx, dp[b]);
            t = t >> 1;
            b++;
        }

        t = num;
        b = 1;
        while (t)
        {
            if ((t & 1) == 1)
                dp[b] = maxx + 1;
            t = t >> 1;
            b++;
        }
    }

    ll ans = -1;
    for (auto &i : dp)
        ans = max(ans, i);

    cout << ans;
}