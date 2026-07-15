#include <iostream>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll dui, cnt = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> dui;
        if (flag)
        {
            if (dui < i)
            {
                if (cnt + dui < i)
                    flag = false;
                else
                    cnt -= i - dui;
            }
            else
                cnt += dui - i;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}