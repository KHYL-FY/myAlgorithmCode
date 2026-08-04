#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;

    int ans = 0;

    vector<int> len(n);
    vector<char> c(n);

    int j = 0, l = 1;
    for (int i = 0; i < n; i++, l++)
    {
        if (a[i] != a[i + 1])
        {
            len[j] = l;
            l = 0;
            c[j] = a[i];
            j++;
        }
    }
    // for (int i = 0; i < j; i++)
    // {
    //     cout << c[i];
    // }
    // cout
    //     << endl;
    // for (int i = 0; i < j; i++)
    // {
    //     cout << len[i];
    // }
    // cout
    //     << endl;
    ans = j;
    for (int i = 1; i < j - 1; i++)
    {
        if (len[i] == 1)
        {
            if (c[i - 1] == c[i + 1])
                ans = min(ans, j - 2);
            else
                ans = min(ans, j - 1);
        }
    }
    // cout << endl;
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}