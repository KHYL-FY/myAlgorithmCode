#include <iostream>

using namespace std;

typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    ll l = -1, r = 1e10;
    if (n == 1)
    {
        ll num;
        cin >> num;
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0)
    {
        ll num;
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            if (i % 2 == 1)
                r = min(r, num);
            else
                l = max(l, num);
        }
        if (r - l > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        ll num;
        for (int i = 1; i <= n; i++)
            cin >> num;
        cout << "NO" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
}