#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll setfind(ll a, vector<ll> &father, vector<ll> &dist)
{
    if (a != father[a])
    {
        ll t = father[a];
        father[a] = setfind(father[a], father, dist);
        dist[a] += dist[t];
    }
    return father[a];
}

void setunion(ll l, ll r, ll v, vector<ll> &father, vector<ll> &dist)
{
    ll lf = setfind(l, father, dist);
    ll rf = setfind(r, father, dist);

    //cout << lf << " " << rf << endl;

    if (lf != rf)
    {
        father[lf] = father[rf];
        dist[lf] = dist[r] - dist[l] + v;
    }
}

ll query(ll l, ll r, vector<ll> &father, vector<ll> &dist)
{
    ll lf = setfind(l, father, dist);
    ll rf = setfind(r, father, dist);

    if (lf != rf)
        return INT64_MAX;
    else
        return dist[l] - dist[r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> father(n + 2);
    vector<ll> dist(n + 2);

    for (int i = 1; i <= n + 1; i++)
    {
        father[i] = i;
    }

    ll l, r, sum;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r >> sum;
        setunion(l, r + 1, sum, father, dist);
    }
    // cout << endl;
    // for (int i = 1; i <= n + 1; i++)
    // {
    //     cout << father[i] << " ";
    // }
    // cout << '\n';
    // for (int i = 1; i <= n + 1; i++)
    // {
    //     cout << dist[i] << " ";
    // }
    // cout << '\n';

    ll ql, qr;
    for (int i = 1; i <= q; i++)
    {
        cin >> ql >> qr;
        ll ans = query(ql, qr + 1, father, dist);
        // for (int i = 1; i <= n + 1; i++)
        // {
        //     cout << father[i] << " ";
        // }
        // cout << '\n';
        // for (int i = 1; i <= n + 1; i++)
        // {
        //     cout << dist[i] << " ";
        // }
        // cout << "\n";
        if (ans == INT64_MAX)
            cout << "UNKNOWN" << '\n';
        else
            cout << ans << '\n';

       // cout << "\n \n";
    }
}