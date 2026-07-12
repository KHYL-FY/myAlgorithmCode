#include <iostream>
#include <string>
using namespace std;

string s, t;
bool sub(int l, int r)
{
    int i = l, j = 0;
    do
    {
        if (s[i] == t[j])
        {
            j++;
        }
        i++;
    } while (i <= r && j < t.length());

    if (j >= t.length())
    {
        // cout << "1";
        return false;
    }

    else
        return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    cin >> s >> t;

    for (int i = 0; i < (int)s.length(); i++)
    {
        for (int j = i; j < (int)s.length(); j++)
        {
            if (j - i + 1 < t.length())
            {
                ans++;
                continue;
            }
            else if (sub(i, j))
            {
                ans++;
            }
        }
    }

    cout << ans;
}