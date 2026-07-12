#include <iostream>
#include <cmath>
#define ll long long

const ll N = 100005;
const ll mod = 1e9 + 7;

using namespace std;

ll fastpow(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}
int main()
{
    int n;

    cin >> n;

    ll sumcast = 0;
    ll cast[N];
    ll xorsum[N] = {0};

    for (int i = 1; i <= n; i++)
        cin >> cast[i];

    for (ll i = 1; i <= n; i++)
    {
        xorsum[i] = xorsum[i - 1] ^ cast[i];
    }
    ll sum = 0;
    for (ll i = 1; i < n; i++)
    {
        sumcast = (sumcast + xorsum[i] * 2 * fastpow(3, n - i - 1)) % mod;
    }
    sumcast += xorsum[n];
    cout << sumcast % mod;
}