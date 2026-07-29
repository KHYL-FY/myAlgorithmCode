#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k == n - 1)
    {
        cout << "-1" << endl;
        return;
    }

    int b = n - k; // 块数
    vector<int> sz(b, 1);

    int cnt0 = (b + 1) / 2;
    int cnt1 = b / 2;

    int rem = k;
    int p0 = 0, p1 = 1;
    while (rem--)
    {
        if (cnt0 <= cnt1)
        {
            sz[p0]++;
            cnt0++;
            p0 += 2;
            if (p0 >= b)
                p0 = 0;
        }
        else
        {
            sz[p1]++;
            cnt1++;
            p1 += 2;
            if (p1 >= b)
                p1 = 1;
        }
    }

    string ans;
    for (int i = 0; i < b; i++)
    {
        ans += string(sz[i], i % 2 == 0 ? '0' : '1');
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
