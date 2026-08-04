#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string a;
    cin >> a;

    string ans;
    int len = (int)a.length();
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '0') 
        {
            string after = a.substr(0, i) + a.substr(i + 1);
            string cur; 
            for (int j = 0; j < (int)after.length(); j++)
            {
                if (after[j] == '1') 
                {
                    string after2 = after.substr(0, j) + after.substr(j + 1);
                    if (cur.empty() || after2 < cur)
                        cur = after2; 
                }
            }
            if (ans.empty() || cur > ans) 
                ans = cur;
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
    {
        solve();
    }
}