#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll get_front(ll a)
{
    while (a >= 10)
    {
        a /= 10;
    }
    return a;
}
ll get_back(ll a)
{
    return a % 10;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> cnt(10);

    ll num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        int f = get_front(num);
        int b = get_back(num);
        ll ans = cnt[f] + 1;
        if (ans > cnt[b])
            cnt[b] = ans;
    }

    ll maxans = 0;
   
    for (auto &i : cnt)
    {
        maxans = max(i, maxans);
    }
    cout << n - maxans;
}