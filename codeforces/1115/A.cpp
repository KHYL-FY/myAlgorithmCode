#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> cnt;
bool cmp(int a, int b)
{
    return cnt[a] > cnt[b];
}
void solve()
{
    int n;
    cin >> n;

    cnt.clear();
    vector<int> num(n);

    int a, len = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (cnt[a] == 0)
        {
            num[len++] = a;
            cnt[a]++;
        }
        else
            cnt[a]++;
    }
    int now = 0, ans = 0;
    bool flag = false;
    int pre = -1;

    sort(num.begin(), num.begin() + len, cmp);

    // for (int i = 0; i < len; i++)
    // {
    //     cout << cnt[num[i]] << " ";
    // }
    // cout << endl;
    while (now < n && !flag)
    {
        for (int i = 0; i < len; i++)
        {

            if (pre == num[i])
            {
                if (now + cnt[num[i]] < n)
                {
                    continue;
                }
                ans += num[i];
                flag = true;
                break;
            }
            now++;
            ans += num[i];
            cnt[num[i]]--;

            // cout << num[i] << " ";
            pre = num[i];
            // cout << " " << pre << endl;
            if (cnt[num[i]] == 0)
            {
                num.erase(num.begin() + i);
                len--;
            }
        }
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
}