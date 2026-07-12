#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
string chufa(string a, ll b)
{
    ll yu = 0;
    ll aNum[10001], ans[10001] = {0};
    ll alen = a.length();
    for (ll i = 0; i < alen; i++)
        aNum[i] = a[i] - '0';

    for (ll i = 0; i < alen; i++)
    {
        ans[alen - i - 1] = (yu * 10 + aNum[i]) / b;
        yu = (yu * 10 + aNum[i]) % b;
    }
    ll len = alen;

    while (ans[len - 1] == 0 && len > 1)
        len--;

    reverse(ans, ans + len);
    string c;

    for (ll i = 0; i < len; i++)
        c += (ans[i] + '0');

    return c;
}

int main(){
    string a;
    cin >> a;
    ll b;
    cin >> b;
    cout << chufa(a, b);
}