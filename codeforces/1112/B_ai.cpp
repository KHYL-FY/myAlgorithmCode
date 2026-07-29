#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    // k = n-1 时只有 1 个块，全相同字符，差值 = n > 1，不可能
    if (k == n - 1)
    {
        cout << "-1\n";
        return;
    }

    int b = n - k; // 块数
    vector<int> sz(b, 1);
    // 初始：奇数索引块是 '0'，偶数索引块是 '1'
    int cnt0 = (b + 1) / 2; // ceil(b/2) 个 0-块
    int cnt1 = b / 2;       // floor(b/2) 个 1-块

    int rem = k;
    int p0 = 0, p1 = 1; // 下一个要扩增的 0-块 / 1-块 的索引
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
    cout << ans << "\n";
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
