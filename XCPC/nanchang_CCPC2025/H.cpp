#include <iostream>

using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> t;
    ll num, ans = 0;
    bool flag = false;
    while (t--)
    {
        ans = 0;
        flag = false;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> num;
            if (num < i)
            {
                flag = true;
                cout << -1 << endl;
                break;
            }
            else{
                ans += (num - i + 1);
                cout << ans << " ";
            }
                
        }
        if (flag == false)
            cout << ans << endl;
    }
}