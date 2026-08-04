#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    map<ll, ll> cnt;
    vector<ll> num(n);
    ll len = 0;

    vector<ll> b(n);

    for (auto &i : b)
    {
        cin >> i;
        if (cnt[i] == 0)
            num[len++] = i;
        cnt[i]++;
    }
    if (cnt[0] == 0)
    {
        cout << "-1" << endl;
        return;
    }
    sort(num.begin(), num.begin() + len);

    map<ll, ll> numtoa;

    ll sum = 0;
    for (int i = 1; i < len; i++)
    {
        if ((num[i] - sum) % cnt[num[i - 1]] != 0)
        {
            cout << -1 << endl;
            return;
        }
        numtoa[num[i - 1]] = (num[i] - sum) / cnt[num[i - 1]];
        sum += numtoa[num[i - 1]] * cnt[num[i - 1]];
    }
    numtoa[num[len - 1]] = numtoa[num[len - 2]] + 1;

    for (int i = 1; i < len; i++)
    {
        if (numtoa[num[i - 1]] >= numtoa[num[i]])
        {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << numtoa[b[i]] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}