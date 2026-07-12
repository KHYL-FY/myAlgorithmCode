#include <iostream>

using namespace std;

size_t f[10000002] = {0}, w[10002] = {0}, v[10002] = {0};
//f[i]表示背包容量为i时的最大价值
//w[i]表示第i个物品消耗时背包容量
//v[i]表示第i个物品的价值
int main()
{
    size_t t, n;
    cin >> t >> n;//t 总容量    n 物品数量

    for (size_t i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    size_t ans = 0;

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = w[i]; j <= t; j++)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);  
            ans = max(f[j], ans);
        }
    }

    cout << ans;
}