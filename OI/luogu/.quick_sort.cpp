
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int l, int r, vector<int> &arr)
{

    int mid = arr[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (arr[j] > mid)
            j--;
        while (arr[i] < mid)
            i++;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    if (l < j)
        quick_sort(l, j, arr);
    if (r > i)
        quick_sort(i, r, arr);

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

    quick_sort(0, n - 1, arr);

    for (auto &i : arr)
        cout << i << " ";
}