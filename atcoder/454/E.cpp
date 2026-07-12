#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int dirx[] = {-1, 1, 0, 0};
const int diry[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

void solve()
{
    int n, a, b;
    int sum = 0;
    cin >> n >> a >> b;

    queue<pair<int, int>> bfs;
    map<pair<int, int>, bool> use;

    char pmv[n + 5][n + 5];
    int prex[n + 5][n + 5];
    int prey[n + 5][n + 5];

    bfs.push({1, 1});
    use[{1, 1}] = true;

    while (!bfs.empty())
    {
        auto top = bfs.front();
        if (!use[{top.first, top.second}])
        {
            sum++;
            auto nxt = top;
            for (int i = 0; i < 4; i++)
            {
                nxt = top;
                nxt.first += dirx[i];
                nxt.second += diry[i];

                if (nxt.first >= 1 && nxt.first <= n && nxt.second >= 1 && nxt.second <= n)
                {
                    if (nxt.first != a || nxt.second != b)
                    {
                        bfs.push(nxt);
                        prex[nxt.first][nxt.second] = top.first;
                        prey[nxt.first][nxt.second] = top.second;
                        pmv[nxt.first][nxt.second] = dir[i];
                    }
                }
            }

            bfs.pop();
        }
    }

    if (sum != n * n - 2)
    {
        cout << "No" << endl;
        return;
    }

    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}