#include <iostream>

using namespace std;

void solve()
{
    string a;
    int n;
    cin >> n;
    cin >> a;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
            cnt++;
    }

    if (cnt == 1)
        cout << 2 << endl;
    else
        cout << 1 << endl;
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