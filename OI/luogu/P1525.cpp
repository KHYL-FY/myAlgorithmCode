
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct crime
{
    int a, b;
    int v;
};

bool cmp(crime x, crime y)
{
    return x.v > y.v;
}

int setfind(int x, vector<int> &father)
{
    if (x == father[x])
        return x;
    else
        return father[x] = setfind(father[x], father);
}

void setunion(int x, int y, vector<int> &father)
{
    int a = setfind(x, father);
    int b = setfind(y, father);

    if (a != b)
        father[b] = a;
}

bool setisSame(int x, int y, vector<int> &father)
{
    int a = setfind(x, father);
    int b = setfind(y, father);

    if (a == b)
        return true;
    else
        return false;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<crime> crimes(m + 1);
    vector<int> father(2 * n + 1);

    for (int i = 1; i <= 2 * n; i++)
        father[i] = i;

    for (int i = 1; i <= m; i++)
        cin >> crimes[i].a >> crimes[i].b >> crimes[i].v;

    sort(crimes.begin() + 1, crimes.end(), cmp);

    // for (int i = 1; i <= m; i++)
    //     cout << crimes[i].a << " " << crimes[i].b << " " << crimes[i].v << endl;

    int ans = 0;

    // int i = 1;
    // cout << (!setisSame(crimes[i].a, crimes[i].a + n, father)) && (!setisSame(crimes[i].b, crimes[i].b + n, father));
    // setunion(crimes[i].a, crimes[i].b + n, father);
    // setunion(crimes[i].a + n, crimes[i].b, father);
    // ans = crimes[i].v;
    for (int i = 1; i <= m; i++)
    {
        // cout << (!setisSame(crimes[i].a, crimes[i].a + n, father)) << " " << (!setisSame(crimes[i].b, crimes[i].b + n, father)) << endl;

        if (!setisSame(crimes[i].a, crimes[i].b, father))
        {
            setunion(crimes[i].a, crimes[i].b + n, father);
            setunion(crimes[i].a + n, crimes[i].b, father);

            // for (int j = 1; j <= 2 * n; j++)
            //     cout << father[j] << " ";
            // cout << endl;
        }
        else
        {
            ans = crimes[i].v;
            break;
        }
    }

    cout << ans;
}