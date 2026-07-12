#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

struct coordinate
{
    ll x, y, id;
};
struct distances
{
    ll id1, id2;
    ll dis = 0;
};
coordinate point[605];
distances d[505];
bool uses[505];

bool cmp(distances a, distances b)
{
    return a.dis > b.dis;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> point[i].x >> point[i].y;
        point[i].id = i;
    }
    ll idis = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            ll dx = point[i].x - point[j].x;
            ll dy = point[i].y - point[j].y;
            idis = dx * dx + dy * dy;
            if (d[i].dis < idis)
            {
                d[i].dis = idis;
                d[i].id1 = i;
                d[i].id2 = j;
            }
        }
    }
    sort(d + 1, d + n + 1, cmp);

    cout << 3 << " " << 3 << endl;

    ll count = 3;
    for (ll i = 1; i < n; i++)
    {
        if (uses[d[i].id1] == false && count != 0)
        {
            cout << d[i].id1 << " ";
            uses[d[i].id1] = true;
            count--;
        }
    }
    cout << endl;
    count = 3;

    for (ll i = 1; i < n; i++)
    {
        if (uses[d[i].id2] == false)
        {
            cout << d[i].id2 << " ";
            uses[d[i].id2] = true;
            count--;
        }
    }
}
