#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, d;
    cin >> n >> d;

    vector<ll> cost(n);
    vector<ll> dis(n - 1);
    for (auto &i : dis)
        cin >> i;
    for (auto &i : cost)
        cin >> i;

    ll fuel = 0, res = 0, mincost = cost[0];
    ll sumcost = 0;
    ll p = 0;
    for (auto x : dis)
    {
        if (res < x)
        {
            mincost = min(mincost, cost[p]);
            x -= res;
            fuel = ((x + d - 1) / d);

            res = fuel * d - x;
            sumcost += fuel * mincost;
            // cout << p << " " << fuel << " " << res << " " << sumcost << endl;
            p++;
        }
        else
        {
            mincost = min(mincost, cost[p]);
            res -= x;
            p++;
        }
        // cout << x << endl;
    }

    cout << sumcost;
}