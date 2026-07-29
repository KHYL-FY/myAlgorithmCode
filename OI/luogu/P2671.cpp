/*
o(n^2)
对颜色进行划分同一种颜色在同一个区,
枚举累加
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod = 10007;
struct node
{
    ll num, color;
    ll id;
};

bool cmp(node a, node b)
{
    if (a.color != b.color)
        return a.color < b.color;

    return a.id < b.id;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<node> a(n);

    for (auto &i : a)
        cin >> i.num;
    for (auto &i : a)
        cin >> i.color;
    for (int i = 0; i < (int)a.size(); i++)
        a[i].id = i + 1;

    sort(a.begin(), a.end(), cmp);

    ll ans = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        for (int j = i + 1; j < n && a[i].color == a[j].color; j++)
        {
            if (a[i].id % 2 == a[j].id % 2)
            {
                // cout << a[i].id << " " << a[j].id << endl;
                ans = (ans + (((a[i].id + a[j].id) % mod) * ((a[i].num + a[j].num) % mod) % mod)) % mod;
            }
        }
    }

    cout << ans;
}