#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// 扩展欧几里得：返回 g = gcd(a, b)，同时得到 x, y 使 a*x + b*y = g
long long extgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// 判断 N 是否能写成 A 的倍数与 B 的倍数（非负）之和
bool canBeExpressed(long long A, long long B, long long N)
{
    // 边界：有一个或两个系数为 0
    if (A == 0 && B == 0)
        return N == 0;
    if (A == 0)
        return N % B == 0;
    if (B == 0)
        return N % A == 0;

    long long d = gcd(A, B);
    // 不互质的情况：N 不能整除 d 则一定无解
    if (N % d != 0)
        return false;

    // 化简为互质方程 a*x + b*y = n
    long long a = A / d;
    long long b = B / d;
    long long n = N / d;

    // b 在模 a 下的逆元（此时 gcd(a, b) = 1）
    long long x, y;
    extgcd(a, b, x, y);              // a*x + b*y = 1
    long long inv = (y % a + a) % a; // b 的逆元，取非负最小正数

    // y0 = (n * inv) % a，为防乘法溢出使用 __int128
    long long y0 = (long long)(((__int128)n * inv) % a);

    // 存在非负整数解当且仅当 b * y0 <= n
    return b * y0 <= n;
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    int num;
    int yueshu;
    bool flag = true;
    int gcdnum = gcd(x, y);
    if (gcdnum == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            if (flag)
            {
                num = i - num < 0 ? num - i : i - num;
                if (num < x * y - x - y && num != 0)
                    flag = false;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            if (flag)
            {
                num = i - num < 0 ? num - i : i - num;
                if (!canBeExpressed(x, y, num))
                    flag = false;
            }
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}