#include <iostream>

#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll left = n, right = 1e8, mid;
    ll sum;
    while (left <= right)
    {
        mid = (right + left) / 2;
        sum = (mid - n + 1) * (n + mid) / 2;

        if (sum >= k)
            right = mid - 1;
        if (sum < k)
            left = mid + 1;
    }

    cout << left - n;
}