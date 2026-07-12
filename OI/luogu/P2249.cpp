#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000002];

// int binary_search(int start, int end, int key)
// {
//     int ret = -1; // 未搜索到数据返回-1下标
//     int mid;
//     while (start <= end)
//     {
//         mid = start + ((end - start) >> 1); // 直接平均可能会溢出，所以用这个算法
//         if (arr[mid] < key)
//             start = mid + 1;
//         else if (arr[mid] > key)
//             end = mid - 1;
//         else
//         { // 最后检测相等是因为多数搜索情况不是大于就是小于
//             ret = mid;
//             break;
//         }
//     }
//     return ret; // 单一出口
// }
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int num;
    int a;
    for (int i = 1; i <= m; i++)
    {
        cin >> num;
        a = lower_bound(arr + 1, arr + n + 1, num)-arr;
        if(arr[a]==num)
        cout << a << " ";
        else
            cout << "-1 ";
        // cout << binary_search(1, n, num)<<" ";
    }
}