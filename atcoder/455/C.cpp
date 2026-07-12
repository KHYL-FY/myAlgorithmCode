#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef unsigned long long ll;

ll a[300005];
ll alen = 0;
map<ll, ll> use;
bool cmp(int x, int y)
{
    return x * use[x] > y * use[y];
}
int main()
{
    ll n, k;
    cin >> n >> k;
    ll num;
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> num;
        sum += num;
        if (use[num] == 0)
        {
            // cout << num << endl;
            a[alen++] = num;
            use[num]++;
        }
        else
        {
            use[num]++;
        }
    }
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " " << use[a[i]] << endl;
    // }
    // cout << endl;
    // cout << sum << endl;

    sort(a, a + alen, cmp);

    for (ll i = 0; i < k; i++)
    {
        sum -= a[i] * use[a[i]];
    }

    cout << sum;
}