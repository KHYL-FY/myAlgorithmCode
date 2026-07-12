//贪心 wrong
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll d = 1;
    ll l;
    bool n = true;
    ll ans = 0;
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> l;
        l *= 2;
        if (n)
        {
            d -= l;
            if (d < 0 )
            {
                ans++;
                n = false;
            }
        }
        else
        {
            d += l;
            if (d > 0 )
            {
                ans++;
                n = true;
            }
        }
    }

    cout << ans;
}