#include <iostream>

using namespace std;
#define ll long long

ll s[4][100005];

void out1()
{
    while (s[1][0] > 0)
    {
        cout << s[3][s[3][0]--] << " ";
        cout << s[1][s[1][0]--] << " ";
    }
    while (s[3][0] > 0)
    {
        cout << s[3][s[3][0]--] << " ";
        cout << s[3][s[3][0]--] << " ";
        cout << s[2][s[2][0]--] << " ";
    }
    while (s[2][0] > 0)
    {
        cout << s[2][s[2][0]--] << " ";
    }
    while (s[0][0] > 0)
    {
        cout << s[0][s[0][0]--] << " ";
    }
}
void out2()
{
    while (s[3][0] > 0)
    {
        cout << s[3][s[3][0]--] << " ";
        cout << s[1][s[1][0]--] << " ";
    }
    while (s[1][0] > 0)
    {
        cout << s[2][s[2][0]--] << " ";
        cout << s[1][s[1][0]--] << " ";
        cout << s[1][s[1][0]--] << " ";
    }
    while (s[2][0] > 0)
    {
        cout << s[2][s[2][0]--] << " ";
    }
    while (s[0][0] > 0)
    {
        cout << s[0][s[0][0]--] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, n;

    cin >> t;
    ll num = 0;

    ll l1, l2, l3;
    while (t--)
    {
        cin >> n;
        s[1][0] = s[2][0] = s[3][0] = s[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            num = num % 4;
            s[num][0]++;
            s[num][s[num][0]] = i;
        }
        l1 = s[1][0];
        l2 = s[2][0];
        l3 = s[3][0];

        if (l3 >= l1)
        {
            l3 = l3 - l1;
            if (l3 > l2 * 2)
            {
                cout << "-1" << endl;
            }
            else
            {
                if (l3 % 2 == 0)
                {
                    l2 = l2 - l3 / 2;
                    if (l2 % 2 == 0)
                    {
                        out1();
                        cout << endl;
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
        else
        {
            l1 = l1 - l3;

            if (l2 * 2 >= l1)
            {
                if (l1 % 2 == 0)
                {
                    l2 = l2 - l1 / 2;
                    if (l2 % 2 == 0)
                    {
                        out2();
                        cout << endl;
                    }
                    else
                    {
                        cout << -1 << endl;
                    }
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}