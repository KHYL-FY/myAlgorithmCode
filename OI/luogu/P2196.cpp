/*
dfs
遍历所有路径,每次需要把路径记录下来,到头了,和当前最大的答案进行比较
大于就保存


迪杰斯特拉?
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
bool g[21][21];
int v[21];
bool use[21];

int ansp[21], path[21], anslen = 0, plen = 0;
int ans = 0;

bool check(int p)
{
    if (p == n)
        return false;
    for (int i = p + 1; i <= n; i++)
    {
        if (!use[i] && g[p][i])
            return true;
    }

    return false;
}
void dfs(int sum, int p)
{
    if (!check(p))
    {
        if (sum >= ans)
        {
            for (int i = 1; i <= plen; i++)
            {
                ansp[i] = path[i];
            }
            anslen = plen;
            ans = sum;
        }
        return;
    }
    use[p] = true;
    for (int i = p + 1; i <= n; i++)
    {
        if (!use[i] && g[p][i])
        {
            path[++plen] = i;
            dfs(sum + v[i], i);
            plen--;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> g[i][j];

    for (int i = 1; i <= n; i++)
    {

        plen = 1;
        path[plen] = i;
        dfs(v[i], i);

        for (int j = 1; j <= n; j++)
            use[j] = 0;
    }

    for (int i = 1; i <= anslen; i++)
    {
        cout << ansp[i] << " ";
    }
    cout << endl
         << ans;
}