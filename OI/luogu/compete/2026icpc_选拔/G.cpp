#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ll n, m;

    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(m);

    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll r = 1e9 + 5, l = 1;
    ll mid;
    ll Acount, Bcount;
    while (l < r)
    {
        mid = (r + l) / 2;
        Acount = upper_bound(a.begin(), a.end(), mid) - a.begin();
        Bcount = b.end() - lower_bound(b.begin(), b.end(), mid);

        if (Acount >= Bcount)
            r = mid;
        else
            l = mid + 1;
    }

    cout << l;
}