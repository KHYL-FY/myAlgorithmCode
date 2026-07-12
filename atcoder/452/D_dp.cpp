#include <iostream>

using namespace std;
typedef long long ll;
const int M = 2e5 + 5;

ll dp[M][60];

int main()
{
    string s, t;

    cin >> s >> t;
    int slen = s.length(), tlen = t.length();

    s = " " + s;
    t = " " + t;

    ll ans = 0;

    for (int i = 1; i <= slen; i++)
    {
        if (s[i] == t[1])
        {
            dp[i][1]++;
        }
        else
        {
            dp[i][0]++;
        }

        for (int j = 1; j <= tlen; j++)
        {
            if (s[i] == t[j])
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }

        for (int j = 0; j <= tlen; j++)
        {
            if (j == tlen || s[i] != t[j + 1])
            {
                dp[i][j] += dp[i - 1][j];
            }
        }

        for (int j = 0; j < tlen; j++)
        {
            ans += dp[i][j];
        }
    }

    // for (int i = 0; i <= slen; i++)
    // {
    //     for (int j = 0; j <= tlen; j++)
    //     {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    cout << ans;
}