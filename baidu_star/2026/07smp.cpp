#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n + 1);

    int sum = 0, k = 0;
    int maxn = 0, maxid = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
            k++;
        else
        {
            sum += a[i];
            cnt[a[i]]++;
            if (a[i] > maxn)
            {
                maxn = a[i];
                maxid = i;
            }
        }
    }
    int other = n - sum;

    bool use = true;
    if (cnt[maxn] > 1 || other > k * (maxn - 1))
        use = false;

    if (other <= maxn)
    {
        cout << maxid;
        return 0;
    }
    if (use)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == -1)
                cout << i << " ";
            if (i == maxid)
                cout << maxid << " ";
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == -1)
                cout << i << " ";
        }
    }
}