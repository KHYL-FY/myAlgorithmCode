#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const ll N = 100001;
const ll MAX = 2147483647;

struct e
{
    ll s, e;
    ll w;
};
vector<e> edge[N];

struct node
{
    ll id;
    ll dis;
    node(ll a, ll b) : id(a), dis(b) {}
    bool operator<(const node &a) const
    {
        return dis > a.dis;
    }
};
map<ll, bool> use;
vector<ll> diss(N);
priority_queue<node> bfs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, s;
    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++)
    {
        diss[i] = MAX;
    }

    e in;
    for (int i = 1; i <= m; i++)
    {
        cin >> in.s >> in.e >> in.w;
        edge[in.s].push_back(in);
    }

    diss[s] = 0;
    bfs.push(node(s, diss[s]));
    while (!bfs.empty())
    {
        // cout << bfs.top().id << " " << bfs.top().dis << endl;
        if (use[bfs.top().id])
        {
            bfs.pop();
            continue;
        }
        diss[bfs.top().id] = bfs.top().dis;
        use[bfs.top().id] = true;

        for (auto i = edge[bfs.top().id].begin(); i != edge[bfs.top().id].end(); i++)
        {
            bfs.push(node((*i).e, (*i).w + diss[bfs.top().id]));
        }
        bfs.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << diss[i] << " ";
    }
}