#include <iostream>

using namespace std;

long long fastpow(long long num, long long b, long long p)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1) 
            ans = ans * num % p;
        num = num * num % p;
        b /= 2;
    }
    return ans;
}
int main()
{
    long long a, b, p;
    cin >> a >> b >> p;

    cout << a << '^' << b << " mod " << p << '=' << fastpow(a, b, p);
}