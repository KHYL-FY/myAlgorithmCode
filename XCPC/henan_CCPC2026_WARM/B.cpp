#include <iostream>

using namespace std;

typedef long long ll;
ll a[1000005];
int main()
{
    ll n;
    cin >> n;

    ll l, r;
    ll maxr = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> l >> r;
        maxr = max(maxr, r);
        a[l]++;
        a[r + 1]--;
    }

    ll ans = 0;
    ll num = 0;
    for (ll i = 0; i <= maxr + 1; i++)
    {
        num += a[i];
        ans = max(ans, num);
    }

    cout << ans;
}