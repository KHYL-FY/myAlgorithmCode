#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> a;
    int num;

    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        a[num]++;
    }

    int ans = 0;
    int cn2;
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] >= 2)
        {
            cn2 = a[i] * (a[i] - 1) * 0.5;
            ans += cn2 * (n - a[i]);
        }
    }

    cout << ans;
}