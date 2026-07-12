#include <iostream>
#include <algorithm>
#define ll unsigned long long
using namespace std;

struct hand
{
    ll left, right;
};

hand dachen[1005];

bool sort_(hand a, hand b)
{
    if (a.left * a.right == b.left * b.right)
    {
        return a.right < b.right;
    }
    return (a.left * a.right) < (b.left * b.right);
}

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
    while (ans[len - 1] == 0)
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

    ll yu = 0;
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

bool maxString(string a, string b)
{
    ll alen = a.length(), blen = b.length();
    if (alen != blen)
    {
        return alen < blen;
    }
    else
    {
        ll i = 0;
        while (i < alen)
        {
            if(a[i]<b[i])
                return a[i] < b[i];
            i++;
        }
    }
    return alen < blen;
}

int main()
{
    ll n;
    string ans;
    cin >> n;

    cin >> dachen[0].left >> dachen[0].right;

    for (ll i = 1; i <= n; i++)
    {
        cin >> dachen[i].left >> dachen[i].right;
    }

    sort(dachen + 1, dachen + 1 + n, sort_);

    string leftSum = to_string(dachen[0].left);
    string jingbi;

    for (ll i = 1; i <= n; i++)
    {
        jingbi = chufa(leftSum, dachen[i].right);

        if (maxString(ans, jingbi))
            ans = jingbi;

        leftSum = chengfa(leftSum, dachen[i].left);
    }

    cout << ans;
}