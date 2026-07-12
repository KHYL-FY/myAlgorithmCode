#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct water
{
    ll time_;
    ll id;
};
water a[1005];

bool cmp(water x, water y)
{
    if (x.time_ == y.time_)
    {
        return x.id < y.id;
    }

    return x.time_ < y.time_;
}
// 1 12 33 55 56 99 99 234 812 1000
int main()
{
    ll n;
    cin >> n;
    double avage = 0;
    ll num = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].time_;
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n, cmp);

    for (ll i = 1; i <= n - 1; i++)
    {
        num += a[i].time_;
        avage += num;
        cout << a[i].id << " ";
    }
    cout << a[n].id << endl;

    cout << fixed << setprecision(2) << avage / (double)n;
}