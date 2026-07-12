#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int v[1005], w[1005];
    int moshi, zongtili, caozuo;
    int dp[1007] = {0};
    int ldp[1007] = {0};

    while (t--)
    {

        for (int i = 1; i <= 1005;i++){
            dp[i] = 0;
            ldp[i] = 0;
        }

        cin >> moshi >> zongtili;
        
        for (int a = 1; a <= moshi; a++)
        {
            cin >> caozuo;
            for (int i = 1; i <= caozuo; i++)
                cin >> v[i];
            for (int i = 1; i <= caozuo; i++)
                cin >> w[i];

            copy(dp, dp + 1005, ldp);

            for (int i = 1; i <= caozuo; i++)
            {
                for (int j = w[i]; j <= zongtili; j++)
                {
                    dp[j] = max(dp[j], ldp[j - w[i]] + v[i]);
                }
            }
        }
        cout << dp[zongtili] << endl;
    }
}