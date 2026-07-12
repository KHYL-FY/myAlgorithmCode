#include <bits/stdc++.h>
// #define debug
using namespace std;
int a[100001];

int i, j, p;
int n;
int k[100001];
void guibing_sort(int l, int r)
{
    int mid = (l + r) / 2;
    if (l == r)
        return;
    else
    {
        guibing_sort(l, mid);
        guibing_sort(mid + 1, r);
    }

    i = l, j = mid+1;
    p = l;

#ifdef debug
    for (int q = 1; q <= n; q++)
        cout << a[q] << " ";
    cout << endl;
#endif

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            k[p] = a[i];
            i++, p++;
        }
        else
        {
            k[p] = a[j];
            j++, p++;
        }
    }

    while (i <= mid)
    {
        k[p] = a[i];
        p++, i++;
    }
    while (j <= r)
    {
        k[p] = a[j];
        p++, j++;
    }

    for (int x = l; x <= r; x++)
    {
        a[x] = k[x];
    }
    return;
}
int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    guibing_sort(1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i]<<" ";
    }
}