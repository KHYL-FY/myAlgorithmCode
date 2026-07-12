#include <iostream>

using namespace std;
#define ll long long

int main()
{
    ll a[200002];
    char b[200002];
    ll t;
    cin >> t;
    ll n, ans = 0;

    for (ll i = 1; i <= t; i++)
    {
        ans = 0;
        cin >> n;
        for (ll q = 1; q <= n; q++)
        {
            cin >> a[q];
            if (a[q] > 0)
                a[q] = 1;
            if (a[q] < 0)
                a[q] = -1;
        }
        for (int p = 1; p <= n; p++)
        {
            cin >> b[p];
        }

        for (ll j = 1; j <= n; j++)
        {
            if (b[j] == '>')
            {
                if (a[j] <= 0)
                {
                    ans++;
                    a[j] = 1;
                }
                else
                    continue;
            }
            if (b[j] == '<')
            {
                if (a[j] >= 0)
                {
                    ans++;
                    a[j] = -1;
                }
                else
                    continue;
            }
            if (b[j] == 'Z')
            {
                if (a[j] * a[j - 1] <= 0)
                {
                    if (a[j - 1] < 0)
                    {
                        a[j] = -1;
                    }
                    if (a[j - 1] > 0)
                    {
                        a[j] = 1;
                    }
                    if (a[j] == 0)
                    {
                        if (a[j - 1] <= -1)
                        {
                            a[j] = -1;
                        }

                        if (a[j - 1] >= 1)
                        {
                            a[j] = 1;
                        }
                    }
                    ans++;
                }
                else
                    continue;
            }
        }
        cout << ans << endl;
    }
}