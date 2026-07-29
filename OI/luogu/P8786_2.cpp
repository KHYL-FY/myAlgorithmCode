/*


*/

#include <iostream>
#include <map>
#include <tuple>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;
ll ans = 0;
ll n, m;
map<tuple<ll, ll, ll>, ll> f;

ll dfs(ll d, ll resn, ll resm)
{
    if (resn < 0 || resm < 0 || d > resm || d < 0 || (d == resm && resn != 0))
        return 0;
    if (f[make_tuple(d, resn, resm)] != 0)
        return f[make_tuple(d, resn, resm)];

    if (resn == 0 && resm == 1 && d == 1)
    {
        // ans = (ans + 1) % mod;
        return 1;
    }
    else
    {
        ll t1 = dfs(d * 2, resn - 1, resm);
        ll t2 = dfs(d - 1, resn, resm - 1);
        ans = (ans + t1) % mod;
        ans = (ans + t2) % mod;
        f[make_tuple(d, resn, resm)] = t1 + t2;
    }

    return 0;
}
int main()
{

    cin >> n >> m;
    dfs(2, n, m);
    cout << ans;
}