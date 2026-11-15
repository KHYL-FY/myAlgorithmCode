#include <iostream>
#include <vector>
using namespace std;
const int M = 10001;

vector<int> g[M];
int a[M];
int n, m;

void dfs(int now, int d)
{
    if (a[now])
        return;
    a[d] = max(now, a[d]);
    for (int i = 0; i < g[now].size(); i++)
    {
        dfs(g[now][i], d);
    }
    return;
}
int main()
{
    cin >> n >> m;

    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
