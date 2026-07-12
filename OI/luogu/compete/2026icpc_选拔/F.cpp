#include <iostream>
using namespace std;

#define ll long long
#define N 1000005
#define mod 998244353

int fact[N], infact[N];
int qmi(ll a, ll b, ll p = 998244353)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return res;
}
void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}
ll c(ll a, ll b)
{
    return (ll)fact[a] * infact[a - b] % mod * infact[b] % mod;
}
int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    init();
    ll num1 = (c(2 * n, n) - c(2 * n, n - 1) + mod) % mod;

    cout << num1;
}
