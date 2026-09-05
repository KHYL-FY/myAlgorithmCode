#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> cnt;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            cnt[v]++;
            sum += v;
        }

        int f = 0, x = 0; 
        for (auto &p : cnt)
            if (p.second > f)
            {
                f = p.second;
                x = p.first;
            }

        int g = n - f;
        long long ans;
        if (f <= g + 1)
            ans = sum; 
        else
            ans = (sum - 1LL * f * x) + 1LL * (g + 2) * x; 
        cout << ans << '\n';
    }
    return 0;
}