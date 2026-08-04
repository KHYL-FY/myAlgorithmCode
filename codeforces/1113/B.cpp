#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    if (n < 2LL * m)
    {
        cout << "NO\n";
        return;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool ok = true;
    for (int k = 0; k < m && ok; k++)
    {
        int l = 0, r = n - 1;
        int p = n; 
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= b[k])
            {
                p = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (!(k < p && p <= n - m + k))
            ok = false;
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}