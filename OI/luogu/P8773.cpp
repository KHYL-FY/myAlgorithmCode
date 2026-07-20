/*

异或的逆运算是他本身,也就是说对于要找a异或b = x,
可以改为对于每个a异或给定的x,是否存在b在数组里,
即a异或x=b.
用f数组,f(i)表示[1,i]中以i为右边界,最大的左边界的值,
因为我们要查询在[l,r]中是否存在合法答案,我们查询f(r),
看看是否f(r)的值大于l.也就是以r为右边界存在着合法答案最小区间
是否在[l,r]之间.如果是,那么答案就是yes,否则就是no.

关于如何具体计算f(i),我们利用递推,需要边建立map边计算f(i)这样能确保
i作为右边界的时候,计算f(i)的时候不会出现值大于i的情况.
递推:如果异或x还没有f(i-1)大,那么采用f(i-1),否则采用异或出来的b对应的位置为值

*/
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 5;
int f[N];
unordered_map<int, int> pos;

int main()
{
    int n, m, x;
    int num;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        pos[num] = i;
        f[i] = max(f[i - 1], pos[num ^ x]);
    }

    int l, r;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        if (f[r] >= l)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}