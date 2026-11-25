#include <iostream>
#include <vector>

using namespace std;

int setfind(int x, vector<int> &father, vector<int> &dist)
{
    if (x != father[x])
    {
        int t = father[x];
        father[x] = setfind(father[x], father, dist);
        dist[x] = (dist[x] + dist[t]) % 3;
    }
    return father[x];
}
void setunion(int l, int r, int v, vector<int> &father, vector<int> &dist)
{
    int lf = setfind(l, father, dist);
    int rf = setfind(r, father, dist);

    if (lf != rf)
    {
        father[lf] = father[rf];
        dist[lf] = (dist[r] - dist[l] + v + 3) % 3;
    }
}
bool setsame(int l, int r, vector<int> &father, vector<int> &dist)
{
    int lf = setfind(l, father, dist);
    int rf = setfind(r, father, dist);

    return lf == rf;
}
int query(int l, int r, vector<int> &dist)
{
    // 此处已确定是一个集合
    //cout << l << " " << r << endl;
    return (dist[l] - dist[r] + 3) % 3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> father(n + 1);
    vector<int> dist(n + 1);
    // 0 同类, 1 吃, 2 被吃

    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }

    int cmd, l, r;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> l >> r;
            if (l > n || r > n)
            {
                ans++;
                // cout << i << endl;
            }

            else
            {

                if (!setsame(l, r, father, dist))
                    setunion(l, r, 0, father, dist);

                else if (query(l, r, dist) != 0)
                {
                    ans++;
                    // cout << i << endl;
                }
            }
        }
        else
        {
            cin >> l >> r;
            if (l > n || r > n)
            {
                ans++;
                // cout << i << endl;
            }
            else
            {
                if (!setsame(l, r, father, dist))
                    setunion(l, r, 1, father, dist);

                else if (query(l, r, dist) != 1)
                {
                    ans++;
                }
            }
        }
    }

    // for (int i = 1; i <= 5; i++)
    // {
    //     cout << father[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= 5; i++)
    // {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    cout << ans;
}