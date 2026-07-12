#include <iostream>
#include <queue>

using namespace std;

struct node
{
    bool light[10][10];
    int foot = 0;
};

queue<node> bfs;

bool use[2][2][2][2][2][2][2][2][2];
bool ifans()
{
    bool ans = true;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            ans = ans && bfs.front().light[i][j];
    return ans;
}
void flag(node &start)
{
    use[start.light[1][1]][start.light[1][2]][start.light[1][3]][start.light[2][1]][start.light[2][2]][start.light[2][3]][start.light[3][1]][start.light[3][2]][start.light[3][3]] = true;

    return;
}

bool ifflag(node &start)
{
    return use[start.light[1][1]][start.light[1][2]][start.light[1][3]][start.light[2][1]][start.light[2][2]][start.light[2][3]][start.light[3][1]][start.light[3][2]][start.light[3][3]];
}
int main()
{
    node start;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> start.light[i][j];

    start.foot = 0;

    bfs.push(start);
    flag(start);

    node next;
    while (!bfs.empty())
    {
        if (ifans())
        {
            cout << bfs.front().foot;
            return 0;
        }

        next = bfs.front();

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                next = bfs.front();
                next.light[i][j] = !next.light[i][j];
                next.light[i - 1][j] = !next.light[i - 1][j];
                next.light[i + 1][j] = !next.light[i + 1][j];
                next.light[i][j - 1] = !next.light[i][j - 1];
                next.light[i][j + 1] = !next.light[i][j + 1];

                if (!ifflag(next))
                {
                    next.foot = bfs.front().foot + 1;
                    bfs.push(next);
                    flag(next);
                }
            }
        }

        bfs.pop();
    }
}