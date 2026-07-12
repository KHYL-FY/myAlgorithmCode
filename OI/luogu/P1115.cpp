#include <bits/stdc++.h>

#define debug
#define ll long long
using namespace std;
ll a[200005];
ll dp[200005];
int main()
{
    ll n;
    cin >> n;

    a[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll maxSum = -0x7fffffff;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] + a[i -1] >= a[i])
        {
            a[i] += a[i - 1];
        }

        maxSum = max(a[i], maxSum);
    }

    cout << maxSum;
}