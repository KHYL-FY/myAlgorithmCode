#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    string a;
    cin >> a;
    ll ans = 0;

    ll len = 0;
    for (ll i = 0; i < (ll)a.length(); i++)
    {
        if (a[i] == a[i + 1])
        {
            len++;
            ans = ans + ((len) * (len + 1) / 2) % 998244353;
            ans %= 998244353;
            len = 0;
        }
        else
            len++;
    }
    ans = ans + ((len) * (len + 1) / 2) % 998244353;
    ans %= 998244353;
    cout << ans;
}