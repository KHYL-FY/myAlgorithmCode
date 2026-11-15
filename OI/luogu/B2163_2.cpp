/*

B2163 棋盘覆盖

输入格式:

输入两行。

第一行一个正整数 k。
第二行两个正整数 x, y, 表示第 x 行第 y 列为特殊方格。

*/

#include <iostream>
#include <vector>

using namespace std;

struct dir
{
    int x, y;
    dir(int a, int b) : x(a), y(b) {}
};

void merge(const int size, const dir spe, const dir ori, int &n, vector<vector<int>> &m)
{
    if (size == 1)
        return;
    n++;
    const int h = size / 2;
    const int sxdir = (spe.x - ori.x) / h;
    const int sydir = (spe.y - ori.y) / h;

    for (int dx = 0; dx <= 1; dx++)
    {
        for (int dy = 0; dy <= 1; dy++)
        {
            if (!(dx == sxdir && dy == sydir))
                m[ori.x + h - 1 + dx][ori.y + h - 1 + dy] = n;
        }
    }

    for (int dx = 0; dx <= 1; dx++)
    {
        for (int dy = 0; dy <= 1; dy++)
        {
            if (dx == sxdir && dy == sydir)
                merge(h, spe, dir(ori.x + h * dx, ori.y + h * dy), n, m);
            else
                merge(h, dir(ori.x + h - 1 + dx, ori.y + h - 1 + dy), dir(ori.x + h * dx, ori.y + h * dy), n, m);
        }
    }
}
int main()
{

    int k;
    int x, y;
    cin >> k;
    cin >> x >> y;

    const int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

    vector<vector<int>> m(pow2[k] + 1, vector<int>(pow2[k] + 1, -1));
    m[x][y] = 0;

    int n = 0;
    merge(pow2[k], dir(x, y), dir(1, 1), n, m);
    for (int i = 1; i <= pow2[k]; i++)
    {
        for (int j = 1; j <= pow2[k]; j++)
            cout << m[i][j] << " ";

        cout << endl;
    }
}