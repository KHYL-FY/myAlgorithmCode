#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    int x, y;
    int head;
};
const int M = 1005;
int H, W;
const int dirx[] = {-1, 1, 0, 0};
const int diry[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};
bool ifans = false;

queue<node> bfs;
char mapp[M][M];
node pre[M][M][4];
char pmv[M][M][4];
bool vis[M][M][4];

bool outmapp(const node &pos)
{
    if (pos.x > H || pos.x <= 0 || pos.y <= 0 || pos.y > W)
    {
        return true;
    }
    return false;
}
bool legal(const node &pos)
{
    if (!outmapp(pos) && mapp[pos.x][pos.y] != '#' && !vis[pos.x][pos.y][pos.head])
        return true;
    else
        return false;
}

int main()
{

    cin >> H >> W;

    node S, G;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> mapp[i][j];
            switch (mapp[i][j])
            {
            case 'S':
                S = {i, j, -1};
                mapp[i][j] = '.';
                break;
            case 'G':
                G = {i, j, -1};
                break;
            }
        }
    }
    bfs.push(S);
    node nextpos = bfs.front();
    vis[S.x][S.y][S.head] = true;

    while (!bfs.empty() && !ifans)
    {
        if (bfs.front().x == G.x && bfs.front().y == G.y)
        {
            ifans = true;
            break;
        }

        nextpos = bfs.front();

        switch (mapp[bfs.front().x][bfs.front().y])
        {
        case '.':
            for (int i = 0; i < 4; i++)
            {
                nextpos = bfs.front();
                nextpos.x += dirx[i];
                nextpos.y += diry[i];
                nextpos.head = i;
                if (legal(nextpos))
                {
                    pre[nextpos.x][nextpos.y][nextpos.head].x = bfs.front().x;
                    pre[nextpos.x][nextpos.y][nextpos.head].y = bfs.front().y;
                    pre[nextpos.x][nextpos.y][nextpos.head].head = bfs.front().head;
                    pmv[nextpos.x][nextpos.y][nextpos.head] = dir[nextpos.head];
                    vis[nextpos.x][nextpos.y][nextpos.head] = true;
                    bfs.push(nextpos);
                }
            }
            break;

        case 'o':
            nextpos = bfs.front();
            nextpos.x += dirx[bfs.front().head];
            nextpos.y += diry[bfs.front().head];
            if (legal(nextpos))
            {
                pre[nextpos.x][nextpos.y][nextpos.head].x = bfs.front().x;
                pre[nextpos.x][nextpos.y][nextpos.head].y = bfs.front().y;
                pre[nextpos.x][nextpos.y][nextpos.head].head = bfs.front().head;
                pmv[nextpos.x][nextpos.y][nextpos.head] = dir[nextpos.head];
                vis[nextpos.x][nextpos.y][nextpos.head] = true;
                bfs.push(nextpos);
            }

            break;

        case 'x':
            for (int i = 0; i < 4; i++)
            {
                if (i == bfs.front().head)
                    continue;
                nextpos = bfs.front();
                nextpos.x += dirx[i];
                nextpos.y += diry[i];
                nextpos.head = i;
                if (legal(nextpos))
                {
                    pre[nextpos.x][nextpos.y][nextpos.head].x = bfs.front().x;
                    pre[nextpos.x][nextpos.y][nextpos.head].y = bfs.front().y;
                    pre[nextpos.x][nextpos.y][nextpos.head].head = bfs.front().head;
                    pmv[nextpos.x][nextpos.y][nextpos.head] = dir[nextpos.head];
                    vis[nextpos.x][nextpos.y][nextpos.head] = true;
                    bfs.push(nextpos);
                }
            }
            break;
        }
        bfs.pop();
    }
    string dirlist;
    node back = bfs.front();
    node nback = bfs.front();
    if (ifans)
    {
        while (back.x != S.x || back.y != S.y)
        {
            dirlist += pmv[back.x][back.y][back.head];
            nback.x = pre[back.x][back.y][back.head].x;
            nback.y = pre[back.x][back.y][back.head].y;
            nback.head = pre[back.x][back.y][back.head].head;
            back = nback;
        }
        reverse(dirlist.begin(), dirlist.end());

        cout << "Yes" << endl;

        cout << dirlist;
    }
    else
        cout << "No";
}
