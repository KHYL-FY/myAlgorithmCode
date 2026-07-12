#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll warer[100001];

int main()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> warer[i];
    }
    sort(warer + 1, warer + 1 + n);

    ll difference = 1000000001;
    for (int i = n; i >= 2; i--)
    {
        difference = min(difference, warer[i] - warer[i - 1]);
    }
    cout << difference;
}