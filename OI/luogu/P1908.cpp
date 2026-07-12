#include <bits/stdc++.h>

// #define debug

using namespace std;
long long a[500005];

long long i, j, p;
long long n;
long long k[500005];
long long ans = 0;

void guibing_sort(long long l, long long r)
{
    long long mid = (l + r) / 2;
    if (l == r)
        return;
    else
    {
        guibing_sort(l, mid);
        guibing_sort(mid + 1, r);
    }

    i = l, j = mid + 1;
    p = l;

#ifdef debug
    for (long long q = l; q <= r; q++)
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
            ans += mid - i + 1;
            
        }
    }

    while (i <= mid)
    {
        k[p] = a[i];
        p++, i++;
        // ans++;
    }
    while (j <= r)
    {
        k[p] = a[j];
        p++, j++;
        // ans++;
    }

    for (long long x = l; x <= r; x++)
    {
        a[x] = k[x];
    }
#ifdef debug
    for (long long q = l; q <= r; q++)
        cout << a[q] << " ";
    cout << endl
         << ans << endl;
#endif
    return;
}
int main()
{

    cin >> n;

    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    guibing_sort(1, n);

    // for (long long i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }

    cout << ans;
}