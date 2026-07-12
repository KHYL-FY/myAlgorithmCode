
// #include <iostream>
// #include <cmath>
// using namespace std;

// typedef long long ll;

// const ll M = 2e5;
// ll num[M + 5];

// ll fast_pow(ll a, ll b)
// {
//     ll ans = 1;

//     while (b)
//     {
//         if (b % 2 == 1)
//         {
//             ans = ans * a;
//         }
//         a = a * a;
//         b /= 2;
//     }

//     return ans;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll n, ans = 0;
//     cin >> n;
//     for (ll i = 1; i <= n; i++)
//     {
//         cin >> num[i];
//     }

//     ll now_ans = 0;
//     for (ll i = 2; i <= n; i++)
//     {
//         if (num[i - 1] > num[i])
//         {
//             // num[i - 1] + num[i] - 1) / num[i])
//             now_ans = ceil(log2(1. * num[i - 1] / num[i]));
//             // cout << now_ans << " ";
//             num[i] = num[i] * fast_pow(2, now_ans);
//             ans += now_ans;
//         }
//     }
//     // cout << endl;

//     cout << ans;
// }
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ll;

const ll M = 2e5;
ll num[M + 10];

ll fast_pow(ll a, ll b)
{
    ll ans = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b /= 2;
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    // ll now_ans = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (num[i - 1] > num[i])
        {
            // ll a = num[i];
            ll cnt = 0;
            while (num[i] < num[i - 1])
            {
                num[i] *= 2;
                cnt++;
            }

            // num[i] = num[i] << cnt;
            ans += cnt;
        }
    }
    // cout << endl;

    cout << ans;
}