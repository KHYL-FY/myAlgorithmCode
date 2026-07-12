#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "最大公因数为" << endl
         << gcd(a, b) << endl;
    cout << "最小公倍数为" << endl
         << lcm(a, b);
}