#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {

        ll n, k;
        cin >> n >> k;

        double num = (n % k) / (double)k;
        ll minans, maxans;
        if (num >= 0.5){
            minans = n / k + 2 * n * ceil(num - 0.5);
            maxans = 
        }

        // if (k == 1)
        // {
        //     cout << (ll)n << " " << (ll)n << endl;
        //     continue;
        // }
        // if (n == k)
        // {
        //     cout << (ll)n << " " << (ll)n + 1 << endl;
        //     continue;
        // }
        // if ((ll)n % (ll)k == 0)
        // {
        //     cout << (ll)n << " " << (ll)n << endl;
        //     continue;
        // }
        // ll minans = floor(n / k) * (ll)k;
        // ll maxans = ceil(n / k) * (ll)k - 1;

        // cout << minans << " " << maxans << endl;
    }
}