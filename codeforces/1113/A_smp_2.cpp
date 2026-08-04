/*
暴力
枚举每个0并删除他,之后再枚举每个1删除他
删1因为需要字典序最小,找到字典序最小的1的位置,
之后再从删除1中找到字典序最大的就是答案
*/
#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string a;
    cin >> a;

    int n = a.length();
    string ans;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
            continue;
        else
        {
            string t = a;
            t.erase(t.begin() + i);

            string cur = t;
            string cur2;

            for (int j = 0; j < (int)cur.length(); j++)
            {
                if (cur[i] == '0')
                    continue;
                else
                {
                    string t2 = cur;
                    t2.erase(t2.begin() + j);
                    if (cur2.empty() || cur2 > t2)
                        cur2 = t2;
                }
            }
            if (ans.empty() || ans < cur2)
                ans = cur2;
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