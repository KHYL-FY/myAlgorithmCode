#include <iostream>
#include <vector>

using namespace std;

struct dir
{
    int x, y;
    dir(int a, int b) : x(a), y(b) {}
};

void merge(const int size, const dir zero, const dir ldir, int &n, vector<vector<int>> &m)
{
    if (size == 1)
        return;
    n++;
    bool xdir = (zero.x - ldir.x < size / 2);
    bool ydir = (zero.y - ldir.y < size / 2); 

    bool sq1 = (xdir && ydir);
    bool sq2 = (xdir && !ydir);
    bool sq3 = (!xdir && ydir);
    bool sq4 = (!xdir && !ydir);

    if (!sq1)
        m[ldir.x + size / 2 - 1][ldir.y + size / 2 - 1] = n;
    if (!sq2)
        m[ldir.x + size / 2 - 1][ldir.y + size / 2] = n;
    if (!sq3)
        m[ldir.x + size / 2][ldir.y + size / 2 - 1] = n;
    if (!sq4)
        m[ldir.x + size / 2][ldir.y + size / 2] = n;
    // if (!sq1)
    //     m[rdir.x / 2][rdir.y / 2] = n;
    // if (!sq2)
    //     m[rdir.x / 2][rdir.y / 2 + 1] = n;
    // if (!sq3)
    //     m[rdir.x / 2 + 1][rdir.y / 2] = n;
    // if (!sq4)
    //     m[rdir.x / 2 + 1][rdir.y / 2 + 1] = n;

    if (sq1)
        merge(size / 2, zero, dir(ldir.x, ldir.y), n, m);
    else
        merge(size / 2, dir(ldir.x + size / 2 - 1, ldir.y + size / 2 - 1), dir(ldir.x, ldir.y), n, m);

    if (sq2)
        merge(size / 2, zero, dir(ldir.x, ldir.y + size / 2), n, m);
    else
        merge(size / 2, dir(ldir.x + size / 2 - 1, ldir.y + size / 2), dir(ldir.x, ldir.y + size / 2), n, m);

    if (sq3)
        merge(size / 2, zero, dir(ldir.x + size / 2, ldir.y), n, m);
    else
        merge(size / 2, dir(ldir.x + size / 2, ldir.y + size / 2 - 1), dir(ldir.x + size / 2, ldir.y), n, m);

    if (sq4)
        merge(size / 2, zero, dir(ldir.x + size / 2, ldir.y + size / 2), n, m);
    else
        merge(size / 2, dir(ldir.x + size / 2, ldir.y + size / 2), dir(ldir.x + size / 2, ldir.y + size / 2), n, m);
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
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}