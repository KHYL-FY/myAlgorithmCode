#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10000005] = {0};
ll b[10000005] = {0};
ll len = 0;
int main()
{
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    a[0] = -1;

    for (ll i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            len++;
        }
        b[len]++;
    }

    sort(b + 1, b + 1 + len);

    b[0] = 0;

    for (ll i = len; i >= 1; i--)
    {
        // for (ll j = 1; j <= len; j++)
        // {
        //     cout << b[j];
        // }
        // cout << endl;

        b[i] = b[i] - b[i - 1];
        b[i - 1] = b[i];
        len--;
        sort(b + 1, b + 1 + len);
    }
    cout << b[0];
    return 0;
}