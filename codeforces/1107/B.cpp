#include <iostream>

using namespace std;

typedef long long ll;

void solve()
{
    ll x, y = 1;
    cin >> x;
    // int len = 0;
    while (x)
    {
        x /= 10;
        y *= 10;
    }
    y++;

    cout << y << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}