#include <iostream>

using namespace std;
long long gcd(int n, int m)
{
    if (n % m == 0)
        return m;
    return gcd(m, n % m);
}
int main()
{
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    // for (long long i = min(a, b); i > 0; i--)
    // {
    //     if (a % i == 0 && b % i == 0)
    //     {
    //         cout << i;
    //         return 0;
    //     }
    // }
}