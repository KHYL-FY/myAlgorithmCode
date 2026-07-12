#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, need;
ll tree[1000005];

ll cut(ll high)
{
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (high >= tree[i])
        {
            continue;
        }
        else
        {
            sum += tree[i] - high;
        }
    }

    return sum;
}

int main()
{
    cin >> n >> need;

    ll start = 0, end = 0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> tree[i];
        start = max(start, tree[i]);
    }

    ll mid;
    ll cuttree;
    while (end <= start)
    {
        mid = (end + start) / 2;

        cuttree = cut(mid);

        if (cuttree < need)
        {
            start = mid - 1;
        }
        else
        {
            end = mid + 1;
        }
    }

    cout << end - 1;
}
