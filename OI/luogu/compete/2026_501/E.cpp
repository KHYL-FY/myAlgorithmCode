#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll pow3[22] = {
    1,
    3,
    9,
    27,
    81,
    243,
    729,
    2187,
    6561,
    19683,
    59049,
    177147,
    531441,
    1594323,
    4782969,
    14348907,
    43046721,
    129140163,
    387420489,
    1162261467,
    3486784401};

ll query(ll i, ll j, ll n)
{
    bool cond1 = pow3[n - 1] <= i && i < 2 * pow3[n - 1];
    bool cond2 = pow3[n - 1] <= j && j < 2 * pow3[n - 1];

    if (n == 1 && (cond1 || cond2))
        return 1;
    else if (n >= 2 && (cond1 || cond2))
        return query(i % pow3[n - 1], j % pow3[n - 1], n - 1);
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    ll qx, qy;

    ll ans = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> qx >> qy;
        if (query(qx, qy, n) == 1)
            ans++;
    }

    cout << ans;
}