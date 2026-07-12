#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXfoot = 5e6;
int H, W;
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
struct node
{
    int x, y;
    int foot = 0;
    int head;
    string dirlist;
};
bool outmapp(node &pos)
{
    if (pos.x > H || pos.x <= 0 || pos.y <= 0 || pos.y > W)
    {
        return true;
    }
    return false;
}
bool legal(node &pos, vector<vector<char>> &mapp)
{
    if (!outmapp(pos) && mapp[pos.x][pos.y] != '#' && pos.foot <= MAXfoot)
        return true;
    else
        return false;
}
queue<node> bfs;

int main()
{

    cin >> H >> W;
    vector<vector<char>> mapp(H + 5, vector<char>(W + 5));

    node S, G;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            cin >> mapp[i][j];
            switch (mapp[i][j])
            {
            case 'S':
                S = {i, j, 0, 0, ""};
                mapp[i][j] = '.';
                break;
            case 'G':
                G = {i, j, 0, 0, ""};
                break;
            }
        }
    bfs.push(S);
    while (!bfs.empty())
    {
        if (bfs.front().x == G.x && bfs.front().y == G.y)
        {
            cout << "Yes" << endl;

            cout << bfs.front().dirlist;

            return 0;
        }

        node nextpos = bfs.front();

        switch (mapp[bfs.front().x][bfs.front().y])
        {
        case '.':
            for (int i = 0; i < 4; i++)
            {
                nextpos = bfs.front();
                nextpos.x += dirx[i];
                nextpos.y += diry[i];
                nextpos.head = i;
                nextpos.foot++;
                if (legal(nextpos, mapp))
                {
                    nextpos.dirlist += dir[i];
                    bfs.push(nextpos);
                }
            }
            break;

        case 'o':
            nextpos = bfs.front();
            nextpos.x += dirx[bfs.front().head];
            nextpos.y += diry[bfs.front().head];
            nextpos.foot++;
            if (legal(nextpos, mapp))
            {
                nextpos.dirlist += dir[bfs.front().head];
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
                nextpos.foot++;
                if (legal(nextpos, mapp))
                {
                    nextpos.dirlist += dir[i];
                    bfs.push(nextpos);
                }
            }
            break;
        }

        bfs.pop();
    }

    cout << "No";
}