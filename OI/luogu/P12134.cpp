#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
ll prints[100005];

bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++)
    {
        cin >> prints[i];
    }

    ll submin = 0x7ffffffffffff;
    ll minp;
    sort(prints + 1, prints + n + 1, cmp);

    for (ll i = 1; i <= n - m + 1; i++)
    {
        if (submin >= (prints[i] * prints[i]) - (prints[i + m - 1] * prints[i + m - 1]))
        {
            submin = (prints[i] * prints[i]) - (prints[i + m - 1] * prints[i + m - 1]);
            minp = i;
        }
    }

    ll ans = (prints[minp] * prints[minp]) - (prints[minp + m - 1] * prints[minp + m - 1]);

    // for (ll i = minp; i < minp + m - 1; i++)
    // {
    //     ans += (prints[i] * prints[i]) - (prints[i + 1] * prints[i + 1]);
    //     // cout << prints[i] << " ";
    // }

    cout << ans;
}