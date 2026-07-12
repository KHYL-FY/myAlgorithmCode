#include <iostream>

using namespace std;
typedef long long ll;
bool iflegal(ll num)
{
    ll a;
    for (int i = 1; i <= 999999; i++)
    {
        a = i * i;
        if (a > num)
            return false;
        else if (a == num)
            break;
    }
    return true;
}
int main()
{
    ll num;
    cin >> num;

    ll a = num, sum = 0;

    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    if (iflegal(num) && iflegal(sum))
    {
        cout << "Yes";
    }
    else
        cout << "No";
}