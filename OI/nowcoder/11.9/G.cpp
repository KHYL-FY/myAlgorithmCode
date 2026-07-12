#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005] = {0}, b[200005] = {0};
ll num[200005];

int main()
{
    ll n;
    cin >> n;
    ll len;
    ll len_a = 0, len_b = 0;
    ll sum = 0;
    while (n--)
    {
        sum = 0;
        len_a = 0;
        len_b = 0;
        cin >> len;

        for (ll i = 1; i <= len; i++)
        {
            cin >> num[i];
        }

        sort(num + 1, num + 1 + len);

        for (ll i = 1; i <= len; i++)
        {
            if (i % 2 == 0)
            {
                a[len_a] = num[i];
                len_a++;
            }
            else
            {
                b[len_b] = num[i];
                len_b++;
            }
        }
        for (ll j = 0; j < len_a - 1; j++)
        {
            sum += a[j] + a[j + 1];
        }

        sum += a[len_a - 1] + b[len_b - 1];

        // cout << a[len_a - 1] << b[len_b - 1] << endl;

        for (ll j = 0; j < len_b - 1; j++)
        {
            sum += b[j] + b[j + 1];
        }

        cout << sum << endl;
    }
}