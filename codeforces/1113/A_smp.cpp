/*
删除0的位置越靠前,则删除0后的字典序越大
删除1的位置越靠前,则删除1后的字典序越小


*/

#include <iostream>

using namespace std;

void solve()
{
    string a;
    cin >> a;

    int n = a.length();
    bool d0 = true, d1 = true;
    for (int i = 0; i < n; i++)
    {
        if (d0 && a[i] == '0')
        {
            d0 = false;
        }
        else if (d1 && a[i] == '1')
        {
            d1 = false;
        }
        else
            cout << a[i];
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
        solve();
}