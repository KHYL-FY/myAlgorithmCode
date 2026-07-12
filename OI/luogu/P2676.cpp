#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    ll n, high;
    cin >> n >> high;

    ll cow[n + 2];

    for (ll i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }

    sort(cow + 1, cow + 1 + n);

    ll ansHigh = 0, ansNum = 0;
    while (ansHigh <= high)
    {
        ansHigh += cow[n];
        n--;
        ansNum++;
    }

    cout << ansNum;
}