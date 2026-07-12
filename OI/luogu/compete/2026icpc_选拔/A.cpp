#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n, l;
    cin >> n;
    ll sum = 0;

    ll maxL = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        maxL = max(l, maxL);
        sum += l;
    }
    sum -= maxL;
    if (sum > maxL)
        cout << 0;
    else
    {
        cout << maxL-sum + 1;
    }
}