#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll a[3005];
int main()
{
    ll t, n;
    ll ans = 0;

    cin >> t;
    ll num;
    while (t--)
    {
        cin >> n;
        ans = 1;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        sort(a + 1, a + 1 + n);

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i; j <= n; j++)
            {
                ll l = j, r = n;
                ll mid, num = 2 * a[j] - a[i];
                while (l <= r)
                {
                    mid = (l + r) / 2;
                    if (a[mid] == num)
                    {
                        l = mid + 1;
                        ll len = max(min(j - i, mid - j) * 2 + 1, min(j - i + 1, mid - j) * 2);
                        ans = max(ans, len);
                    }
                    else if (a[mid] > num)
                        r = mid - 1;
                    else if (a[mid] < num)
                        l = mid + 1;
                }
            }
        }

        cout << ans << endl;
    }
}