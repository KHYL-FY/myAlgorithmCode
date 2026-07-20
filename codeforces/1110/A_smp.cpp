/*
i表示第i只猪
当i属于[1,k]的时候,这些猪一定不能朝左,因为朝左需要有在他左边k个朝右的猪
这一定是不可能的,最大也只能有k-1个猪
同理i属于[n-k+1,n],这些猪都不能朝右

而中间的不用管,因为两边处理好后,无论中间它朝左还是朝右,都至少有k只猪与他相对.

如果发现n < 2k,此时就会与上面的条件发生了矛盾,我们也就可以知道,这时候无解

*/

#include <iostream>

using namespace std;

void solve()
{
    string a;
    int n, k;
    cin >> n >> k;
    cin >> a;

    if (2 * k > n)
    {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {

        if (a[i] == 'L')
            cnt++;
    }

    for (int i = n - 1; i >= n - k; i--)
    {

        if (a[i] == 'R')
            cnt++;
    }

    cout << cnt << endl;
    return;
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