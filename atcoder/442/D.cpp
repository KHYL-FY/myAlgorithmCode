#include <iostream>

using namespace std;

#define ll long long

ll a[200010];
int main()
{
    ll n, q;
    cin >> n >> q;
    a[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i] + a[i - 1];
    }
    int caozuo;
    ll x;
    ll numx, numx1;
    ll l, r;
    // 2 9 10 18 1
    for (ll i = 1; i <= q; i++)
    {
        cin >> caozuo;
        if (caozuo == 1)
        {
            cin >> x;
            numx = a[x] - a[x - 1];
            numx1 = a[x + 1] - a[x];
            a[x] = a[x] - numx + numx1;
        }
        if (caozuo == 2)
        {
            cin >> l >> r;
            cout << a[r] - a[l-1] << endl;
        }
    }
}