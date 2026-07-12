#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // 排序
        sort(a.begin(), a.end());

        int ans = 1; // 至少可以取1个元素

        // 枚举最小值位置 i 和中位数位置 j
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // 计算需要的最大值
                ll max_val = 2 * a[j] - a[i];

                // 二分查找最后一个等于 max_val 的位置
                int left = j, right = n - 1, k = -1;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (a[mid] == max_val)
                    {
                        k = mid;
                        left = mid + 1; // 继续向右找最后一个
                    }
                    else if (a[mid] < max_val)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }

                if (k == -1)
                    continue; // 没有找到 max_val

                // 计算左边和右边可用的元素数量
                int left_cnt = j - i;  // i 到 j-1 的元素个数
                int right_cnt = k - j; // j+1 到 k 的元素个数

                // 奇数长度
                int len_odd = min(left_cnt, right_cnt) * 2 + 1;
                ans = max(ans, len_odd);

                // 偶数长度
                int len_even = min(left_cnt + 1, right_cnt) * 2;
                ans = max(ans, len_even);
            }
        }

        cout << ans << endl;
    }

    return 0;
}