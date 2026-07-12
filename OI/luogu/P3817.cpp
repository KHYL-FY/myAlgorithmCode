#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;

    ll a[n + 5];

    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;

    for (ll i = 2; i <= n; i++)
    {

        if (a[i] + a[i - 1] > x)
        {
            if (a[i] - (a[i] + a[i - 1] - x) < 0)
            {
                ans += a[i] + a[i - 1] - x;
                a[i] = 0;
                a[i - 1] = a[i - 1] - (x - a[i]);
            }
            else
            {
                ans += a[i] + a[i - 1] - x;
                a[i] = a[i] - (a[i] + a[i - 1] - x);
            }
        }
    }

    cout << ans;
    return 0;
}
