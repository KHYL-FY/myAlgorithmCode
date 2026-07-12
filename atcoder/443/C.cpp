#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n, t;
    cin >> n >> t;
    if (n == 0)
    {
        cout << t;
        return 0;
    }
    ll a = 0, b = 0, ans = 0;

    cin >> a;
    ans += a;
    b = a;

    ll open = a + 100;
    for (ll i = 2; i <= n; i++)
    {
        cin >> a;
        if (a <= open)
            continue;

        ans += (a - open);
        open = a + 100;
        // if (a - b > 100 && a > open)
        //     ans += (a - b - 100);
        // b = a;
        // cout << ans << endl;
    }
    if (t - open > 0)
        ans += (t - open);
    cout << ans;
}