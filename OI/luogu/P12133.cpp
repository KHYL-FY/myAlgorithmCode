#include <iostream>
using namespace std;
#define ll unsigned long long
int main()
{
    ll t;
    cin >> t;

    ll a, b, c, k;
    ll newA, newB, newC;
    bool equalABC = false;

    for (ll i = 1; i <= t; i++)
    {
        cin >> a >> b >> c >> k;

        while (k > 0)
        {
            newA = (b + c) / 2;
            newB = (a + c) / 2;
            newC = (a + b) / 2;
            k--;
            a = newA, b = newB, c = newC;
            if (a == b && a == c && b == c){
                equalABC = true;
                break;
            }
        }

        cout << newA << " " << newB << " " << newC << endl;
    }
}