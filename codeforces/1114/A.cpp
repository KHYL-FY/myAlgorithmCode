#include <iostream>

using namespace std;

void give(int &a, int &b, int &c)
{
    if (a > b && b > c)
        a--, c++;
    if (a > c && c > b)
        a--, b++;
    if (b > a && a > c)
        b--, c++;
    if (b > c && c > a)
        b--, a++;
    if (c > a && a > b)
        c--, b++;
    if (c > b && b > a)
        c--, a++;
    return;
}
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while (a != b && b != c && c != a)
    {
        // cout << a << b << c << endl;
        give(a, b, c);
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}