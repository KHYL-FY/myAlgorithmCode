#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

const ll N = 2e5 + 5;
ll fact[N], infact[N];
int qmi(ll a, ll b, ll p = mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void init()
{
    fact[0] = infact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}

ll c(ll a, ll b)
{
    if (b < 0 || b > a)
        return 0;
    return fact[a] * infact[a - b] % mod * infact[b] % mod;
}

const ll M = 2e5 + 5;
ll da[M], db[M], dc[M];
void d(ll a[], ll l, ll r)
{
    if (l > r)
        return;
    a[l]++;
    a[r + 1]--;

    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    ll n;

    cin >> n;

    ll l, r;
    ll onlyA = 0, epty = 0;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> l >> r;
        d(da, l, r);
        d(db, n - r, n - l);
        d(dc, max(l, n - r), min(r, n - l));
    }
    da[0] = db[0] = dc[0] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        da[i] += da[i - 1];
        db[i] += db[i - 1];
        dc[i] += dc[i - 1];
        // cout << da[i] << " " << db[i] << " " << dc[i] << endl;
    }

    for (ll i = 1; i <= n - 1; i++)
    {
        if (da[i] + db[i] - dc[i] != n)
            continue;
        onlyA = da[i] - dc[i];
        epty = i - onlyA;
        ans = (ans + c(dc[i], epty)) % mod;
    }
    cout << ans;
}