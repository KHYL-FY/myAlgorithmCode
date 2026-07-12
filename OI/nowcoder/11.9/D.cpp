#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    if (n > 19375331)
    {
        cout << n - (n - 19375331) + 1;
    }
    else
        cout << n;
}