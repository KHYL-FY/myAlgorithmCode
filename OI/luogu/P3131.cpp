#include <iostream>

using namespace std;

#define ll long long

ll s[50005];
ll mod[7][50005];

int main()
{
    int n;
    cin >> n;
    s[0] = 0;
    ll mod_num = 0;
    mod[0][0] = mod[1][0] = mod[2][0] = mod[3][0] = mod[4][0] = mod[5][0] = mod[6][0] = 0;
    mod[0][0] = 1, mod[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
        mod_num = s[i] % 7;
        mod[mod_num][++mod[mod_num][0]] = i;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << s[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;

    for (int i = 1; i <= 6; i++)
    {
        // cout << mod[i][mod[i][0]] << " " << mod[i][1] << endl;
        ans = max(mod[i][mod[i][0]] - mod[i][1], ans);
    }
    if (mod[0][0] > 1)
    {
        cout << max(mod[0][mod[0][0]] - mod[0][1] + 1, ans);
    }
    else
        cout << ans;
    // if (mod[0][mod[0][0]] - mod[0][1] + 1 > ans)
    // {
    //     cout << mod[0][mod[0][0]] - mod[0][1] + 1;
    // }
    // else
    //     cout << ans - 1;
}