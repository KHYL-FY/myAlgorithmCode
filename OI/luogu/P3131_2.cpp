#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll s[50005];
int main()
{
    int n;
    cin >> n;
    s[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
        s[i] %= 7;
    }
    ll ans = 0;
    for (int i = 0; i <= 6; i++)
    {
        auto l = find(s, s + n, i);
        auto r = s + n;
        while (l <= r)
        {   
            if (*l == *r)
                ans = max(ans, (ll)(r - l));
            r--;
        }
    }

    cout << ans;
}