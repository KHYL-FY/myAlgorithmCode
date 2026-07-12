#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y, foot;
};

int main()
{
    int huati[30][4];

    int n, m;
    cin >> n >> m;

    char mapp[305][305];
    queue<node> bfs;
    node qidian;
    node zhongdian;
    map<pair<int, int>, pair<int, int>> hua;

    int dirx[5] = {0, 1, -1, 0, 0};
    int diry[5] = {0, 0, 0, 1, -1};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mapp[i][j];
            if (mapp[i][j] <= 'Z' && mapp[i][j] >= 'A')
            {
                if (huati[mapp[i][j] - 'A' + 1][1] != 0)
                {
                    huati[mapp[i][j] - 'A' + 1][3] = i;
                    huati[mapp[i][j] - 'A' + 1][4] = j;
                }
                else
                {
                    huati[mapp[i][j] - 'A' + 1][1] = i;
                    huati[mapp[i][j] - 'A' + 1][2] = j;
                }
            }
            if (mapp[i][j] == '@')
            {
                qidian.x = i, qidian.y = j, qidian.foot = 0;
                bfs.push(qidian);
            }
            if (mapp[i][j] == '=')
            {
                zhongdian.x = i;
                zhongdian.y = j;
            }
        }
    }
    // cout << zhongdian.x << zhongdian.y << zhongdian.foot;

    node weizhi;
    while (!bfs.empty())
    {
        if (bfs.front().x == zhongdian.x && bfs.front().y == zhongdian.y)
        {
            cout << bfs.front().foot;
            return 0;
        }
        // cout << bfs.front().x << bfs.front().y << " " << bfs.front().foot << endl;
        for (int i = 1; i <= 4; i++)
        {
            weizhi.x = bfs.front().x + dirx[i];
            weizhi.y = bfs.front().y + diry[i];
            weizhi.foot = bfs.front().foot + 1;
            if (mapp[weizhi.x][weizhi.y] != '#' && mapp[weizhi.x][weizhi.y] != '+')
            {
                //bfs.push(weizhi);
                if (mapp[weizhi.x][weizhi.y] <= 'Z' && mapp[weizhi.x][weizhi.y] >= 'A')
                {
                    if (weizhi.x == huati[mapp[weizhi.x][weizhi.y] - 'A' + 1][1] && weizhi.y == huati[mapp[weizhi.x][weizhi.y] - 'A' + 1][2])
                    {
                        weizhi.x = huati[mapp[bfs.front().x + dirx[i]][bfs.front().y + diry[i]] - 'A' + 1][3];
                        weizhi.y = huati[mapp[bfs.front().x + dirx[i]][bfs.front().y + diry[i]] - 'A' + 1][4];
                        bfs.push(weizhi);
                    }
                    else
                    {
                        weizhi.x = huati[mapp[bfs.front().x + dirx[i]][bfs.front().y + diry[i]] - 'A' + 1][1];
                        weizhi.y = huati[mapp[bfs.front().x + dirx[i]][bfs.front().y + diry[i]] - 'A' + 1][2];
                        bfs.push(weizhi);
                    }
                }
                else
                    bfs.push(weizhi);
            }
        }
        mapp[bfs.front().x][bfs.front().y] = '+';
        bfs.pop();
    }
    //cout << bfs.front().foot;
}