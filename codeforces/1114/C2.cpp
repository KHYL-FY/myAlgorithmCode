#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    int num;

    string a, b;
    cin >> a >> b;

    int aodd = 0, aeven = 0;
    int bodd = 0, beven = 0;
    vector<int> ao(n), bo(n);
    vector<int> ae(n), be(n);

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] == '1')
            {
                if (i % 2 == 0)
                    ae[aeven++] = i;
                else
                    ao[aodd++] = i;
            }
            if (b[i] == '1')
            {
                if (i % 2 == 0)
                    be[beven++] = i;
                else
                    bo[bodd++] = i;
            }
        }
    }
    if (aodd == bodd && aeven == beven)
    {
        ll ans = 0;
        for (int i = 0; i < aodd; i++)
        {
            ans += ((ao[i] > bo[i] ? ao[i] - bo[i] : bo[i] - ao[i])) / 2;
        }
        for (int i = 0; i < aeven; i++)
        {
            ans += ((ae[i] > be[i] ? ae[i] - be[i] : be[i] - ae[i])) / 2;
        }
        cout << ans << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}