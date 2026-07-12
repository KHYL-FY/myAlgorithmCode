#include <iostream>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k % n == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        k %= n;
        if (n % 2 == 0 && k % 2 == 1) // n偶 k奇
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            if (n % 2 == 0 && k % 2 == 0) // n偶 k偶
            {
                cout << n / 2 - (k % n) / 2 << endl;
                return;
            }
            else
            {
                if (n % 2 == 1 && k % 2 == 0) // n奇 k偶
                {
                    cout << n - (k % n) / 2 << endl;
                    return;
                }
                else // n奇 k奇
                {
                    cout << n - ((n / 2) + (k % n + 1) / 2) << endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}