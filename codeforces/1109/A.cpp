#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    a = a + ".";
    int maxAns = 0, nowlen = 0;
    if (a[0] == '#')
        nowlen++;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1] && a[i - 1] == '#')
        {
            maxAns = max((nowlen + 2 - 1) / 2, maxAns);
            nowlen = 0;
        }
        else
        {
            if (a[i] == '#')
                nowlen++;
        }
    }
    cout << maxAns << endl;
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