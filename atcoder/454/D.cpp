#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string c1, c2;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < (int)a.length(); i++)
    {
        c1 += a[i];
        if ((int)c1.size() >= 4 && c1.substr(c1.size() - 4, 4) == "(xx)")
        {
            c1.erase(end(c1) - 4, end(c1));
            c1 += "xx";
        }
    }
    for (int i = 0; i < (int)b.length(); i++)
    {
        c2 += b[i];
        if ((int)c2.size() >= 4 && c2.substr(c2.size() - 4, 4) == "(xx)")
        {
            c2.erase(end(c2) - 4, end(c2));
            c2 += "xx";
        }
    }

    if (c1 == c2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}