#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;

    ll a[100005], sum[100005];

    sum[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];

        sum[i] = a[i] + sum[i - 1];
    }

    ll m;
    cin >> m;
    ll l, r;

    for (ll i = 1; i <= m; i++)
    {
        cin >> l >> r;

        cout << sum[r] - sum[l-1] << endl;
    }
}