/*
P2249 【深基13.例1】查找

输入格式
第一行 2 个整数 n 和 m，表示数字个数和询问次数。
第二行 n 个整数，表示这些待查询的数字。
第三行 m 个整数，表示询问这些数字的编号，从 1 开始编号。

输出格式
输出一行，m 个整数，以空格隔开，表示答案。
如果没有找到的话输出 −1 .

*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    int q;
    for (int i = 1; i <= m; i++)
    {
        cin >> q;
        auto it = lower_bound(arr.begin(), arr.end(), q);
        int p = it - arr.begin();
        if (it != arr.end() && *it == q)
            cout << p + 1 << " ";
        else
            cout << "-1 ";
    }
    
}
