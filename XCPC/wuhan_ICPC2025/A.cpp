#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

int main()
{
    ll t, n, q;

    cin >> t;

    ll r, l, ans = 0;
    ll a[105][4];

    while (t--)
    {
        cin >> n >> q;

        ans = 0;
        for (ll i = 1; i <= n; i++)
            a[i][2] = a[i][3] = -1;

        for (ll i = 1; i <= n; i++)
            cin >> a[i][1];

        ll p;
        for (ll i = 1; i <= q; i++)
        {
            cin >> p >> l >> r;

            if (a[p][2] == -1)
                a[p][2] = l;
            else
                a[p][2] = max(a[p][2], l);
            if (a[p][3] == -1)
                a[p][3] = r;
            else
                a[p][3] = min(a[p][3], r);
        }

        for (ll i = 1; i <= n; i++)
        {
            if (a[i][2] > a[i][3])
            {
                ans = -1;
                break;
            }

            if (a[i][2] != -1 && a[i][3] != -1)
            {
                if (a[i][1] > a[i][2] && a[i][1] < a[i][3])
                    continue;
                else
                    ans += (min(abs(a[i][1] - a[i][2]), abs(a[i][1] - a[i][3])));
            }
        }

        cout << ans << endl;
    }
}