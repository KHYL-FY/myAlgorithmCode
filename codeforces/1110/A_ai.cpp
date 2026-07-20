#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    if (2 * k > n)
    {
        cout << -1 << "\n";
        return;
    }

    int pre[101] = {0};
    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] = pre[i] + (s[i] == 'R');
    }

    auto countR = [&](int l, int r) -> int { 
        if (l > r)
            return 0;
        return pre[r + 1] - pre[l];
    };

    int ans = n + 1; 

    for (int r = k; r <= n - k; ++r)
    {
        int front_cost = k - countR(0, k - 1);
        int back_cost = countR(n - k, n - 1);
        int mid_len = n - 2 * k;
        int cntR_mid = countR(k, n - k - 1);
        int need_R = r - k; 
        int mid_cost = abs(cntR_mid - need_R);

        int total = front_cost + back_cost + mid_cost;
        ans = min(ans, total);
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
    {
        solve();
    }
    return 0;
}