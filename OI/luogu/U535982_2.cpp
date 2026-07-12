#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, ans1 = 0, ans2 = 0;
    string a[3];
    string b;
    while (t--)
    {
        ans1 = ans2 = 0;
        cin >> n;
        a[1].clear();
        a[2].clear();
        for (int i = 0; i < 2 * n; i++)
        {
            if (i % 2 == 0)
            {
                a[1] += 'A';
                a[2] += 'B';
            }
            else
            {
                a[1] += 'B';
                a[2] += 'A';
            }
        }

        cin >> b;

        for (int i = 0; i < 2 * n; i++)
        {
            if (a[1][i] != b[i])
                ans1++;
            if (a[2][i] != b[i])
                ans2++;
        }

        cout << min(ans1 / 2, ans2 / 2) << endl;
    }
}