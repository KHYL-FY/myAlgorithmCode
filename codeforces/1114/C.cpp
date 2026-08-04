#include <iostream>
#include <cmath>

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
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            if (i % 2 == 0)
                aeven++;
            else
                aodd++;
        }
        if (b[i] == '1')
        {
            if (i % 2 == 0)
                beven++;
            else
                bodd++;
        }
    }
    if (aodd == bodd && aeven == beven)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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