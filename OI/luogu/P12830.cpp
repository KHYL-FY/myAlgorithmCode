#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
int main()
{

    ll cnt = 0;
    for (ll i = 1; i <= 2025; i++)
    {
        for (int j = 1; j <= 2025; j++)
        {
            if (lcm(i, j) == 2025)
            {
                cout << i << " " << j << endl;
                cnt++;
            }
        }
    }

    cout << cnt;

    
}