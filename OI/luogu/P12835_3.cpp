/**
 * P12835 [蓝桥杯 2025 国 B] 蓝桥星数字
 *
 * 题意：找出第 n 个"奇偶交替"的数字（从 10 开始）。
 * 奇偶交替：相邻数位奇偶性不同，如 10（奇偶）、21（偶奇）。
 *
 * 思路：
 * 1. d 位数中，满足条件的个数为 9 × 5^(d-1)（d ≥ 2）
 * 2. 先确定答案的位数 len
 * 3. 从高位到低位逐位贪心构造：
 *    - 枚举当前位可能的数字（需满足奇偶交替约束）
 *    - 计算以该数字开头的剩余位有多少种合法填法（= 5^(剩余位数)）
 *    - 若 n > 该计数则跳过，否则选定该数字，继续下一位
 */

#include <iostream>
using namespace std;
typedef long long ll;

// pow5[i] = 5^i，预计算防止重复计算
ll pow5[30];

int main()
{
    // 预计算 5 的幂次
    pow5[0] = 1;
    for (int i = 1; i <= 15; i++)
    {
        pow5[i] = pow5[i - 1] * 5;
    }

    ll n;
    cin >> n;

    // 1. 确定答案的位数 len
    // prefix[d] = 位数 ≤ d 的合法数字总数
    ll len = 1;
    ll prefix = 0; // prefix[len] 表示 ≤ len 位的总数
    while (prefix < n)
    {
        len++;
        // len 位数的合法数字个数 = 9 × 5^(len-1)
        prefix += 9 * pow5[len - 1];
    }
    // 此时 prefix 是 ≤ len 位的总数，n 落在 len 位数中
    // 回退：n 变成在 len 位数中的排名（1-indexed）
    n -= (prefix - 9 * pow5[len - 1]);

    // 2. 逐位构造答案
    ll ans = 0;
    int prevParity = -1; // 上一位的奇偶性，-1 表示尚未确定

    for (int pos = 1; pos <= len; pos++)
    {
        // 枚举当前位可能的数字
        for (int dgt = 0; dgt <= 9; dgt++)
        {
            // 第一位不能是 0
            if (pos == 1 && dgt == 0) continue;

            // 非第一位：必须与上一位奇偶性不同
            if (pos > 1 && (dgt % 2) == prevParity) continue;

            // 以当前数字开头，剩余 (len-pos) 位的合法填法数
            ll cnt = pow5[len - pos];

            if (n > cnt)
            {
                n -= cnt;
            }
            else
            {
                ans = ans * 10 + dgt;
                prevParity = dgt % 2;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}