/*
题目给出的有个关键信息,a和b中的数均不相同
判断b最后是不是能从a合并而来

a和b中的数全都不一样而最后要变成b,那么也就是说,a中的每一个数都要经历一次合并
每个数经历了一次合并数量一定会减少到原来的一半以下,所以如果a元素个数n不大于b中元素个数的2倍的话,答案肯定是NO

接着看合并的条件,要想变成b中的元素,我们姑且叫它为z,需要在a中有一个大于z的元素和一个小于z的元素,我们分别称他们为y和x.所以要想判断b中的元素能不能通过a合并而来,我们需要找y和x才行.还有一点y和z之间还可以有别的a中的元素,只要上界和下界能够包裹住这个z,几个元素最后都能合并成z.

那我们就更极端一点判断存不存在这个x和y.将a和b都排序,对于b中最小的元素,它必须比a中最小的元素大,不然就不存在这个下界x了.反之,如果a最小的元素都小于b中最小的元素了,说明对于这个z我们的选择的下界x至少有一个,不一定只有一个但它一定存在.接下来找上界,因为对于b每个元素合并都要有下界,所以前面n-m个元素我们都不能在去用他了,不然极限的情况下下界个数肯定不够用.从n-m开始找,如果说这个元素他大于b中最小的元素,那么这个上界也找到了,它存在.依此类推,b中第二小的元素b[1](我们下标是从0开始),要看a[1]是否小于他,上界a[n-m+1]是否大于它,看看上界和下界是否存在.所以条件就是对于每个b中的每个元素b[i],判断a[i]是不是小于b[i],a[n-m+1]是不是大于b[i],这两个条件都满足那么就看下一个b.有一个不满足条件答案就是NO.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    if (n < 2 * m)
    {
        cout << "NO" << endl;
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool ans = true;
    for (int i = 0; i < b.size() && ans; i++)
    {
        if (a[i] > b[i])
            ans = false;
        if (a[n - m + i] < b[i])
            ans = false;
    }

    cout << (ans ? "YES" : "NO") << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}