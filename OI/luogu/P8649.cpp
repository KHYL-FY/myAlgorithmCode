#include <iostream>

using namespace std;

#define ll unsigned long long

ll s[100005];
ll k_count[100005];
int main()
{
    ll n, k;
    cin >> n >> k;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
        s[i] %= k;
        k_count[s[i]]++;
    }
    ll ans = 0;
    k_count[0]++;
    for (int i = k - 1; i >= 0; i--)
    {
        //cout << k_count[i] << endl;
        ans = ans + (k_count[i] * (k_count[i] - 1) / 2);
    }

    cout << ans;
}