#include <iostream>
#include <string>
using namespace std;

string s, t;
int sub(int l)
{
    int i = l, j = 0;
    while (i <= (int)s.length() && j < (int)t.length())
    {
        if (s[i] == t[j])
        {
            j++;
        }
        i++;
    }
    return i - 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    cin >> s >> t;

    int fl;
    int i = 0, n = s.length();
    while (i < n)
    {
        fl = sub(i);
        ans += (fl - i);
        i++;
    }

    cout << ans;
}