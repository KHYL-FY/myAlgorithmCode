#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int N = 3e5 + 5;
vector<int> a[N];
map<int, bool> use;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int v1, v2;
    for (int i = 1; i <= m; i++)
    {
        cin >> v1 >> v2;
        a[v1].push_back(v2);
    }

    queue<int> bfs;
    bfs.push(1);
    use[1] = true;

    while (!bfs.empty())
    {
        for (auto i = a[bfs.front()].begin(); i != a[bfs.front()].end(); i++)
        {
            if (!use[*i])
            {
                bfs.push(*i);
                use[*i] = true;
            }
        }

        bfs.pop();
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (use[i])
            ans++;
    }

    cout << ans;
}