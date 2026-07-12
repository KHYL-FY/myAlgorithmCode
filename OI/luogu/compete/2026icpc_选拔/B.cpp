#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int n;
    int a[1005];
    int ans = 0, amax = 0;
    while (t--)
    {
        cin >> n;
        ans = 0, amax = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            amax = max(amax, a[i]);
        }
        ans = amax;
        int k = 0;
        for (int i = 1; i <= amax; i++)
        {
            k = 0;
            for (int j = 1; j <= n; j++)
            {
                k += ((a[j] + i - 1) / i) - 1;
            }
            k += i;
            ans = min(ans, k);
        }

        cout << ans << endl;
    }

    return 0;
}