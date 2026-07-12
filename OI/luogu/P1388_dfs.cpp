/* dfs 被hack掉一个数据
 正解 dp

5 3
1 1 0 0 0

 */
#include <iostream>
    using namespace std;
typedef long long ll;

ll n, mul, add, ans = 0;
ll num[20];
char opt[20]; // 存操作符

// 括号 DFS，计算最大值
void bra_dfs(ll pos, ll current_sum, ll product)
{
    if (pos > n)
    {
        ans = max(ans, product * current_sum);
        return;
    }

    if (pos == 1)
    {
        bra_dfs(pos + 1, num[1], 1);
        return;
    }

    if (opt[pos - 1] == '+')
    {
        // 当前符号是 +，累加到 current_sum
        bra_dfs(pos + 1, current_sum + num[pos], product);
    }
    else
    {
        // 当前符号是 *，可以选择：
        // 1. 把前面的 current_sum 乘到 product，然后开始新的 sum
        bra_dfs(pos + 1, num[pos], product * current_sum);
        // 2. 不加括号，把数字加入 current_sum
        bra_dfs(pos + 1, current_sum * num[pos], product);
    }
}

// 符号 DFS
void opt_dfs(ll pos, ll nmul, ll nadd)
{
    if (nmul > mul || nadd > add)
        return;

    if (pos == n)
    {
        bra_dfs(1, 0, 1);
        return;
    }

    // 放乘号
    if (nmul < mul)
    {
        opt[pos] = '*';
        opt_dfs(pos + 1, nmul + 1, nadd);
    }

    // 放加号
    if (nadd < add)
    {
        opt[pos] = '+';
        opt_dfs(pos + 1, nmul, nadd + 1);
    }
}

int main()
{
    cin >> n >> mul;
    add = n - mul - 1; // 剩下的全是加号

    for (ll i = 1; i <= n; i++)
        cin >> num[i];

    opt_dfs(1, 0, 0); // 从第1个符号开始 DFS

    cout << ans << endl;

    return 0;
}