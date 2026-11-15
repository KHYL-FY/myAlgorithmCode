#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct dir
{
    ll x, y, z;
};
struct udbound
{
    ll maxbound, minbound;
};

ll setFind(const ll &x, vector<ll> &father)
{
    if (x == father[x])
        return x;
    return father[x] = setFind(father[x], father);
}

void setUnion(const ll &a, const ll &b, vector<ll> &father, vector<udbound> &setbound)
{
    ll x = setFind(a, father);
    ll y = setFind(b, father);

    if (x <= y)
    {
        father[y] = x;
        setbound[x].maxbound = max(setbound[x].maxbound, setbound[y].maxbound);
        setbound[x].minbound = min(setbound[x].minbound, setbound[y].minbound);
    }
    else
    {
        father[x] = y;
        setbound[y].maxbound = max(setbound[x].maxbound, setbound[y].maxbound);
        setbound[y].minbound = min(setbound[x].minbound, setbound[y].minbound);
    }
}

bool setisSame(const ll &a, const ll &b, vector<ll> &father)
{
    ll x = setFind(a, father);
    ll y = setFind(b, father);

    if (x == y)
        return true;
    else
        return false;
}

bool isconnect(const dir &a, const dir &b, const ll &r)
{
    ll xdis = a.x - b.x;
    ll ydis = a.y - b.y;
    ll zdis = a.z - b.z;

    ull dis = xdis * xdis + ydis * ydis + zdis * zdis;
    if (dis <= 4 * r * r)
        return true;
    else
        return false;
}

void solve()
{
    ll n, h, r;
    cin >> n >> h >> r;

    vector<dir> coord(n);
    vector<ll> father(n);
    vector<udbound> setbound(n);

    ll p = 0;
    for (auto &i : coord)
    {
        cin >> i.x >> i.y >> i.z;

        father[p] = p;
        setbound[p].minbound = i.z - r;
        setbound[p].maxbound = i.z + r;
        p++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (setisSame(i, j, father))
                continue;
            else
            {
                if (isconnect(coord[i], coord[j], r))
                {
                    setUnion(i, j, father, setbound);
                }
            }
        }
    }
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (setbound[i].maxbound >= h && setbound[i].minbound <= 0)
        {
            ok = true;
        }
    }
    if (ok)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}