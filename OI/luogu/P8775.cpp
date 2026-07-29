/*
我们假设跳跃距离为y,当我们从起点出发(这个起点可以说岸边也可以是石头)
我们所能跳的y区间内,我们需要经过2x次,也就是说这个区间的总和必须超过2x次,
才能保证我们区间,能经过2x次,不然肯定撑不过2x次跳跃,我们把这个起点推广一下,
对于每块石头或岸边作为起点,我们都得保证y区间内的和超过或等于2x次,我们才能渡过这一部分,

所以有该结论:对于每个y区间总和必须大于等于2x次,这个y才是合法的.

接下来利用二分,枚举y区间,找到这个最小的y.O(nlogn)

似乎也可以双指针?
*/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n, x;

// bool check(ll y, vector<ll> sum)
// {
//     for (int i = y; i < n ; i++)
//     {
//         if (sum[i] - sum[i-y] < 2 * x)
//             return false;
//     }
//     return true;
// }

bool check(ll y, vector<ll> sum)
{
    for (int i = 1; i <= n - y; i++)
    {
        if (sum[i + y - 1] - sum[i - 1] < 2 * x)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;

    vector<ll> sto(n);
    vector<ll> sum(n);

    for (int i = 1; i < n; i++)
    {
        cin >> sto[i];
        sum[i] = sum[i - 1] + sto[i];
    }

    ll l = 1, r = n, mid;
    ll ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid, sum))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}