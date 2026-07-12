#include <bits/stdc++.h>
#define ll long long
using namespace std;

string a;
int main()
{
    ll n, i = 0;
    cin >> n;
    ll num1 = 0, num2 = 0, sum = 0, num;
    ll l;

    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        num1 = 0, num2 = 0;

        cin >> a;
        num1 = a[0] - '0';
        l = a.length();
        for (int j = 1; j < l; j++)
        {
            num2 = num2 + (a[j] - '0');
            num2 = num2 * 10;
        }
        num2 /= 10;
        sum = num1 + num2;

        num1 = 0, num2 = 0;
        num1 = a[l - 1] - '0';
        for (int j = 0; j < l - 1; j++)
        {
            num2 = num2 + (a[j] - '0');
            num2 = num2 * 10;
        }
        num2 /= 10;
        sum = max(num1 + num2, sum);


        cout << sum<<endl;
    }
    

    // for (ll x = 1; x <= n; x++)
    // {
    //     num1 = 0;
    //     num2 = 0;
    //     sum = 0;
    //     i = 0;

    //     while ((a[i] = getchar()) != '\n' || (a[i] = getchar()) != EOF)
    //         i++;

    //     for (int q = 0; q < i; q++)
    //     {
    //         cout << a[q];
    //     }
    //     // cout << endl;
    //     for (ll j = 0; j < i - 1; j++)
    //     {
    //         l = 0;
    //         r = j;

    //         while (l <= j)
    //         {
    //             num1 += (a[l] - '0');
    //             num1 *= 10;
    //             l++;
    //         }
    //         while (r <= i)
    //         {
    //             num2 += (a[r] - '0');
    //             num2 *= 10;
    //             r++;
    //         }
    //         sum = max(sum, num1 + num2);
    //     }
    //     // cout << sum << endl;
    // }
}