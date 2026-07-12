#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll a = 1, b = 1, c;

    cout << a << " " << b << " ";
    for (int i = 3; i <= 40; i++)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
        if (i % 5 == 0)
        {
            cout << endl;
        }
    }
}