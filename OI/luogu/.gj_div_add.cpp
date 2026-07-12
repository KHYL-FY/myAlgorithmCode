#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll yu = 0;
string chengfa(string a, ll b)
{
    ll aNum[10001], ans[10001] = {0};
    ll alen = a.length();
    for (ll i = 0; i < alen; i++)
        aNum[i] = a[alen - i - 1] - '0';
    for (ll i = 0; i < alen; i++)
        ans[i] += aNum[i] * b;

    ll len = alen + to_string(b).length();

    for (ll i = 0; i < len; i++)
    {
        ans[i + 1] += (ans[i] / 10);
        ans[i] %= 10;
    }
    while (ans[len - 1] == 0 && len > 1)
        len--;

    reverse(ans, ans + len);
    string c;

    for (ll i = 0; i < len; i++)
        c += (ans[i] + '0');

    return c;
}
string chufa(string a, ll b)
{
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
int main()
{
    freopen("gjdivdj.in", "r", stdin);
    freopen("gjdivdj.out", "w", stdout);
    int m;
    string n;
    cin >> n >> m;
    string a = chufa(n, m);
    cout << a << endl;
    cout << yu;
    // for (ll i = 0; i < a.length(); i++){
    //     int num = a[i] - '0';
    //     cout << num;
    // }
}