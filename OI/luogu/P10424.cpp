#include <iostream>
#include <algorithm>
using namespace std;

bool goodnum(string &a)
{
    for (int i = 0; i < (int)a.length(); i++)
    {
        int num = a[i] - '0';

        if ((i + 1) % 2 == 1)
        {
            if (!(num % 2 == 1))
                return false;
        }
        if ((i + 1) % 2 == 0)
        {
            if (!(num % 2 == 0))
                return false;
        }
    }

    return true;
}
int main()
{
    int n;
    cin >> n;

    string a;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        a = to_string(i);
        reverse(a.begin(), a.end());
        // cout << a << endl;
        if (goodnum(a))
            ans++;
    }
    cout << ans;
}
