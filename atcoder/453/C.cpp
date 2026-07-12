#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, ans = 0;
vector<ll> l(25);

void dfs(ll p, ll nowpos, ll nowans)
{
    if (p > n)
    {
        ans = max(nowans, ans);
        return;
    }
    for (ll i = -1; i <= 1; i += 2)
    {
        ll nextpos = nowpos;
        ll nextans = nowans;
        nextpos += l[p] * i;
        if (nextpos < 0 && nowpos > 0)
            nextans++;
        else if (nextpos > 0 && nowpos < 0)
            nextans++;

        dfs(p + 1, nextpos, nextans);
    }

    return;
}
int main()
{
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        cin >> l[i];
        l[i] *= 2;
    }

    dfs(1, 1, ans);

    cout << ans;
}