#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

#define ll unsigned long long
#define mod 998244353

set<ll> exponent;
map<ll, ll> counts;

ll fastpow(ll num, ll b, ll p = mod) // num^b % p
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = ans * num % p;
        num = num * num % p;
        b /= 2;
    }
    return ans;
}
int main()
{
    ll t, n, m;
    ll len = 0;
    cin >> t;

    ll a, b, sum = 0, k;
    while (t--)
    {
        counts.clear();
        exponent.clear();
        sum = 0;
        k = 0;
        cin >> n >> m;

        for (ll i = 1; i <= n; i++)
        {
            cin >> a >> b;
            if (counts[b] == 0)
            {
                exponent.insert(b);
                counts[b] = a;
            }
            else
                counts[b] += a;
            sum = (sum + fastpow(2, b) * a) % mod;
        }

        for (auto i = exponent.begin(); i != exponent.end(); i++)
        {
            if (counts[*i] <= m)
                continue;
            ll surplus = counts[*i] % m;
            ll line = counts[*i] / m;
            ll next = line / 2 * m;
            if (line % 2 == 1)
            {
                next += surplus;
                counts[*i] = n - surplus;
            }
            else
                counts[*i] = surplus;

            if (counts[*i + 1] == 0)
            {
                exponent.insert(*i + 1);
                counts[*i + 1] = next;
            }
            else
                counts[*i + 1] += next;
        }

        for (auto i = exponent.begin(); i != exponent.end();)
        {
            if (counts[*i] == 0)
            {
                auto p = i;
                i++;
                exponent.erase(*p);
                continue;
            }
            i++;
        }
        k = fastpow(2, *exponent.end());
        bool ans = false;
        for (auto i = exponent.begin(); i != exponent.end(); i++)
        {
            if ((k + fastpow(2, *i)) % mod >= sum)
            {
                cout << k << endl;
                break;
            }
        }
        // for (auto j = exponent.begin(); j != exponent.end(); j++)
        // {
        //     cout << *j << " ";
        // }
        // cout << endl;
        // for (auto j = exponent.begin(); j != exponent.end(); j++)
        // {
        //     cout << counts[*j] << " ";
        // }
    }
}