#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int x, y;
    int t;
    bool operator<(const node &a) const
    {
        return t < a.t;
    }
};
// bool cmp(node a, node b)
// {
//     return a.t < b.t;
// }
int find(int x, vector<int> &father)
{
    // int root = x;
    if (father[x] == x)
        return x;
    return father[x] = find(father[x], father);
    // while (father[root] != root)
    // {
    //     root = father[root];
    // }

    // int p = x;
    // while (father[x] != x)
    // {
    //     p = father[x];
    //     father[x] = root;
    //     x = p;
    // }
    // return root;
}

void union_(int x, int y, vector<int> &father, vector<int> &sz)
{
    int rootx = find(x, father);
    int rooty = find(y, father);

    if (rooty == rootx)
        return;
    if (sz[rootx] >= sz[rooty])
    {
        sz[rootx] += sz[rooty];
        father[rooty] = rootx;
    }
    else
    {
        sz[rootx] += sz[rooty];
        father[rooty] = rootx;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> father(n + 1), sz(n + 1);
    vector<node> edge(m);

    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        sz[i] = 1;
    }

    for (auto &i : edge)
    {
        cin >> i.x >> i.y >> i.t;
    }

    sort(edge.begin(), edge.end());

    // for (auto &i : edge)
    // {
    //     cout << i.x << " " << i.y << " " << i.t << endl;
    // }
    int ans = 0, maxsz = 0;
    for (auto &i : edge)
    {
        if (maxsz == n)
            break;
        else
        {
            ans = i.t;
            union_(i.x, i.y, father, sz);
            int root = find(i.x, father);
            maxsz = max(maxsz, sz[root]);
        }
    }

    if (maxsz != n)
        cout << "-1";
    else
        cout << ans;
}