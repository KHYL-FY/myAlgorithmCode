#include <iostream>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k;
    ll m;
    cin >> n >> k >> m;

    if (m < k)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    ll special = m - k + 1;
    for (int i = 1; i <= n; ++i)
    {
        ll val = (i % k == 0) ? special : 1;
        cout << val << (i == n ? '\n' : ' ');
    }

    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}