#include <iostream>

using namespace std;

const int M = 3e5 + 5;

int set[M];               // i表示第i张卡片 [i]表示它所在的位置 如果他的pre是空的那么这个位置信息才有用
int ncard[M], precard[M]; // i表示第i张卡片 [i]表示他的下一张是几号
int ans[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        set[i] = i, ncard[i] = -1, precard[i] = -1;

    int from, to;

    for (int i = 1; i <= q; i++)
    {
        cin >> from >> to;

        ncard[to] = from;
        if (precard[from] != -1)
            ncard[precard[from]] = -1;
        precard[from] = to;
        set[from] = set[to];
    }

    // for (int i = 1; i <= n; i++)
    //     cout << ncard[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << precard[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << set[i] << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (precard[i] != -1)
            continue;

        int p = i;
        ans[set[i]]++;
        while (ncard[p] != -1)
        {
            ans[set[i]]++;
            p = ncard[p];
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}