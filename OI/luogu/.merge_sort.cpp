
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(int l, int r, vector<int> &arr)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid, arr);
    merge_sort(mid + 1, r, arr);

    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];

    for (int p1 = l, p2 = 0; p1 <= r && p2 < k; p1++, p2++)
        arr[p1] = tmp[p2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    merge_sort(0, n - 1, arr);

    for (auto &i : arr)
        cout << i << " ";
}