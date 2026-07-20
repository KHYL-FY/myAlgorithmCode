
#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    vector<int> suml(105);
    vector<int> sumr(105);

    int n, k;
    cin >> n >> k;

    string pig;
    cin >> pig;
    for (int i = 1; i <= n; i++)
    {
        if (pig[i - 1] == 'R')
        {
            sumr[i] = sumr[i - 1] + 1;
            suml[i] = suml[i - 1];
        }

        else
        {
            sumr[i] = sumr[i - 1];
            suml[i] = suml[i - 1] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << suml[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << sumr[i] << " ";
    bool flag = false;
    int pair = 0, ans = 0x7fffff;

    for (int i = 1; i <= n; i++)
    {
        if (pig[i - 1] == 'L')
        {
            pair = sumr[i];
            if (pair + suml[i] >= k)
            {
                flag = true;
                ans = min(ans, k - pair > 0 ? k - pair : pair - k);
            }
        }
    }

    vector<int> resuml(105);
    vector<int> resumr(105);
    for (int i = n; i >= 1; i--)
    {
        if (pig[i - 1] == 'R')
        {
            resumr[i] = resumr[i - 1] + 1;
            resuml[i] = resuml[i - 1];
        }

        else
        {
            resumr[i] = resumr[i - 1];
            resuml[i] = resuml[i - 1] + 1;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (pig[i - 1] == 'R')
        {
            pair = suml[i];
            if (pair + sumr[i] >= k)
            {
                flag = true;
                ans = min(ans, k - pair > 0 ? k - pair : pair - k);
            }
        }
    }
    if (!flag)
        cout << -1 << endl;
    else
        cout << ans << endl;
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