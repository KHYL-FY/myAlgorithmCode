//wrong

/*
建立一个结构体数组,结构体包含相邻两块石头的差值

如d[i]表示第i块石头与i+1块的间距.还有对应的编号

之后需要对差值大小进行排序,差值递增.
要想得到最短跳跃距离的最大值我们利用贪心从最小的开始操作,但是差值是相邻两块石头的应该拿哪一块呢?

我们还需利用map使得我们可以快速查找相邻两块石头差值相邻数据,也就是
要知道d[i-1]和d[i+1]的值,但是此时我们已经进行了排序,数值已经被打乱了,
这时map派上用场了,map我们以编号为key,差值为value,能够快速查找相邻的值.

如果是d[i-1]更小那么我们拿掉d[i]这两个相邻石头编号更小的那一个反之则反,
特殊的,如果相邻的石头有起点或终点,那么就拿另一颗,因为终点和起点不能动.

这样重复m次即可
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

struct node
{
    ll d;
    ll id;
};
map<ll, ll> idtov;

ll stone[50005];
node dsto[50005];

bool cmp(node a, node b)
{
    return a.d < b.d;
}
int main()
{
    int l, n, m;
    cin >> l >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> stone[i];
        dsto[i].d = stone[i] - stone[i - 1];
        dsto[i].id = i;
        idtov[i] = dsto[i].d;
    }

    sort(dsto + 1, dsto + 1 + n, cmp);

    for (int i = 1; i <= m; i++)
    {

    }
}