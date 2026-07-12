#include <iostream>

// #define debug
using namespace std;

int n;
int a[100001];

void quick_sort(int l, int r)
{
    int i = l, j = r;
    int mid = a[(l + r) / 2];

#ifdef debug
    for (int q = 1; q <= n; q++)
        cout << a[q] << " ";
    cout << endl;
#endif

    do
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }

    } while (i <= j);

#ifdef debug
    for (int q = 1; q <= n; q++)
        cout << a[q] << " ";
    cout << endl;
#endif
    if (l < j)
        quick_sort(l, j);
    if (r > i)
        quick_sort(i, r);
}
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    quick_sort(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}