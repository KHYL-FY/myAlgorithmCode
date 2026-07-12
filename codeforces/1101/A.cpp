#include <iostream>

using namespace std;

typedef long long ll;

ll a[105];
void solve()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0x7ffffffffff;
    ll l = 0, r = 0;
    ll p;
    for (int i = 1; i <= n; i++)
    {
        l = 0, r = 0;
        p = a[i];
        for (int j = 1; j <= n; j++)
        {
            if (a[j] < p)
                l++;
            else if (a[j] > p)
                r++;
        }
        ans = min(ans, max(l, r));
    }

    cout << ans<<endl;
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