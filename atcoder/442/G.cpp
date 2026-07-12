#include <iostream>
#include <cstring>

using namespace std;
#define ll long long
ll w[10002] = {0};
ll k[10002];
string f[10002], v[10002];

string addition(string a, string b)
{
    ll len_a = a.length();
    ll len_b = b.length();

    for (ll i = 0; i < len_a / 2; i++)
    {
        swap(a[i], a[len_a - 1 - i]);
    }
    for (ll i = 0; i < len_b / 2; i++)
    {
        swap(b[i], b[len_b - 1 - i]);
    }

    if (len_a < len_b)
        a.insert(len_a, len_b - len_a, '0');
    else
        b.insert(len_b, len_a - len_b, '0');

    ll result[10000] = {0};
    for (ll i = 0; i < max(len_a, len_b); i++)
    {
        result[i] += (a[i] - '0') + (b[i] - '0');
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    ll len_result = max(len_a, len_b) + 1;
    while (len_result > 1 && result[len_result - 1] == 0)
        len_result--;

    string result_str;
    for (ll i = len_result - 1; i >= 0; i--)
    {
        result_str += (result[i] + '0');
    }

    return result_str;
}
string houmaxstring(string a, string b)
{
    ll alen = a.length(), blen = b.length();
    if (alen != blen)
    {
        if (alen > blen)
            return a;
        else
            return b;
    }
    else
    {
        ll i = 0;
        while (i < alen)
        {
            if (a[i] < b[i])
                return b;
            else if (a[i] > b[i])
                return a;
            i++;
        }
    }
    return a;
}

int main()
{
    ll t, n;
    cin >> n >> t;

    for (ll i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i] >> k[i];
    }
    string ans = "0";

    for (ll i = 1; i <= t; i++)
    {
        f[i] = "0";
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll q = 1; q <= k[i]; q++)
        {
            for (ll j = t; j >= w[i]; j--)
            {
                f[j] = houmaxstring(f[j], addition(f[j - w[i]], v[i]));
                ans = houmaxstring(f[j], ans);
                cout << ans<<endl;
            }
        }
    }

    cout << ans;
    return 0;
}