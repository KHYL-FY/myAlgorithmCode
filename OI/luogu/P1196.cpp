#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int M = 30002;
vector<int> father(M);
vector<int> dist(M);
vector<int> setsize(M);
void debug_()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << setsize[i] << " ";
    }
    // cout << endl;
    // for (int i = 1; i <= 5; i++)
    // {
    //     cout << father[i] << " ";
    // }
    cout << endl
         << endl;
}
int setfind(int x)
{
    if (x != father[x])
    {
        int t = father[x];
        // setsize[t] += setsize[x];
        father[x] = setfind(father[x]);
        dist[x] += dist[t];
    }

    return father[x];
}

void setunion(int l, int r)
{
    int lf = setfind(l);
    int rf = setfind(r);

    // int v = setsize[lf] + setsize[rf];
    // debug_();
    if (lf != rf)
    {
        // cout << v << "  " << setsize[lf] << " " << setsize[rf] << " " << dist[lf] << " " << dist[r] << " " << dist[l] << endl;

        father[lf] = rf;
        dist[lf] = setsize[rf];
        setsize[rf] += setsize[lf];

        // cout << v << "  " << setsize[lf] << " " << setsize[rf] << " " << dist[lf] << " " << dist[r] << " " << dist[l] << endl;
    }
    // debug_();
}

int query(int l, int r)
{
    int lf = setfind(l);
    int rf = setfind(r);

    // cout << lf << " " << rf << endl;
    // cout << l << " " << r << endl;
    // debug_();
    if (lf != rf)
        return -1;
    else
        return abs(dist[l] - dist[r]) - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i < M; i++)
    {
        father[i] = i;
        // dist[i] = 0;
        setsize[i] = 1;
    }

    char cmd;
    int l, r;

    for (int i = 1; i <= t; i++)
    {
        cin >> cmd;
        if (cmd == 'C')
        {
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
        else
        {
            cin >> l >> r;
            setunion(l, r);
        }
    }
}