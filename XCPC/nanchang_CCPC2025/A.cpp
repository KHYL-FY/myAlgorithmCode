#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll a[3005];
bool cmp(ll a, ll b)
{
    return a > b;
}

int main()
{
    ll t;
    ll n, k;
    cin >> t;

    ll hold_capsules = 0;
    while (t--)
    {
        cin >> n >> k;
        hold_capsules = 0;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort(a + 1, a + 1 + n, cmp);

        for (int i = 1; i <= n; i++)
        {
            if (a[i] - 1 + hold_capsules >= (n - i) * k)
            {
                if (hold_capsules > (n - i) * k)
                    cout << hold_capsules + i << endl;
                else
                    cout << (n - i) * k + i << endl;
                break;
            }
            else
            {
                hold_capsules += a[i] - 1;
            }
        }
    }

    return 0;
}