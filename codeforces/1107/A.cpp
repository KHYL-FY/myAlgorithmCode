#include <iostream>

using namespace std;
void solve()
{
    int x, y;
    cin >> x >> y;

    if (x % y == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}