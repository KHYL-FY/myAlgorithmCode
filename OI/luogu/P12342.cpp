#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    typedef long long ll;
    ll n;
    cin >> n;
    vector<ll> a(n, 0), b(n, 0);

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll p1 = n, p2 = n;
    ll cnt = 0;
    while (p2)
    {
        if (a[p1 - 1] <= b[p2 - 1])
        {
            cnt++;
            p2--;
        }
        else
        {
            p1--;
            p2--;
        }
    }
    cout << cnt;
}