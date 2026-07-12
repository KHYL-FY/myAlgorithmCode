#include <iostream>

using namespace std;

#define ll long long
int main()
{
    ll n, t;
    cin >> t;
    ll num, max_num = 0;
    while (t--)
    {
        cin >> n;
        if (n < 3 || n == 4)
            cout << "-1" << endl;
        else if (n % 3 == 1)
            cout << n / 3 - 1 << endl;
        else
            cout << n / 3 << endl;
    }

    return 0;
}