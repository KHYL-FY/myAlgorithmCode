#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
ll numth = 1;
ll n;
ll count = 1;
void solve()
{
    string snum = "1";
    while (count--)
    {
        snum += '0';
    }

    ll num = stoll(snum);
    // cout << num;
    bool flag = false;
    bool ou;
    while (numth < n)
    {
        flag = true;
        // numth++;
        num++;
        snum = to_string(num);
        // cout << num << endl;

        if ((snum[0] - '0') % 2 == 0)
        {
            ou = true;
        }
        else
            ou = false;

        for (int i = 1; i < snum.length(); i++)
        {
            if (ou)
            {
                if ((snum[i] - '0') % 2 == 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    ou = false;
                }
            }
            else
            {
                if ((snum[i] - '0') % 2 == 1)
                {
                    flag = false;
                    break;
                }
                else
                    ou = true;
            }
        }
        if (flag)
            numth++;
    }
    cout << num;
}
int main()
{

    cin >> n;

    if (n <= 45)
    {
        solve();
        return 0;
    }
    else
    {
        numth *= 9;
    }
    ll sum = 45;
    while (numth < n)
    {
        if (numth * 5 + sum >= n)
        {
            // numth *= 5;
            solve();
            // ll num = 1;
            // while (numth * num < n)
            // {
            //     num++;
            // }
            // num--;
            // numth *= num;
            // cout << numth;
            break;
        }
        else
        {
            sum += numth;
            numth *= 5;
            count++;
        }
    }
    // cout << numth;
}