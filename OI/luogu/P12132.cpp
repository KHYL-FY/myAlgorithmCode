#include <iostream>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll num, ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> num;
        if (num != 1)
        {
            ans++;
        }
    }
    cout << ans;
}