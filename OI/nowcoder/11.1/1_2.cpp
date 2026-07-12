#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll num = 0;
ll jinzhi2(ll x)
{

    if (x == 0)
    {
        return x % 2;
    }
    int y = jinzhi2(x / 2);
    num = num * 10 + y;
    return x % 2;
}

int main()
{
    ll a,b;
    cin >> a>>b;

    // ll sum;
    ll y = jinzhi2(a);
    num = num * 10 + y;
    ll num1 = num;

    num = 0;

    y = jinzhi2(b);
    num = num * 10 + y;
    ll num2 = num;

    cout << num1 + num2;
}