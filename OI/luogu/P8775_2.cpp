/*
O(n)
双指针
i作为起点,j找到大于2x的点,
全都扫一遍用最大的答案

*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    vector<ll> sto(n);

    for (int i = 1; i < n; i++)
    {
        cin >> sto[i];
    }

    ll ysum = 0, j = 0, ans = 0;
    for (int i = 1; i < n; i++)
    {
        while (ysum < 2 * x && j < n)
            ysum += sto[++j];
        ans = max(ans, j - i + 1);
        ysum -= sto[i];
    }

    cout << ans;
}