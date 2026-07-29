/*


*/

#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int asum = 0, bsum = 0;
    vector<int> a(n + 5);
    vector<int> b(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        asum += a[i];
        bsum += b[i];
        if (a[i] == b[i])
            continue;
        else
            flag = false;
    }
    if (flag)
    {
        cout << 0 << endl;
        return;
    }
    if (bsum == n || asum == 0)
    {
        cout << -1 << endl;
        return;
    }
    
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
            sum += a[i];
    }

    if (sum % 2 == 0)
        cout << 2 << endl;

    else
        cout << 1 << endl;

    return;
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