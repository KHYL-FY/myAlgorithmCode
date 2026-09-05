#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 5);

    int maxx = 0;
    int maxxid = 0;
    int sum = 0;
    bool use = true;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (maxx <= a[i])
        {
            if (maxx == a[i])
                use = false;
            else
            {
                maxx = a[i];
                maxxid = i;
                use = true;
            }
        }
        if (a[i] != -1)
            sum += a[i];
    }
    int other = n - sum;

    bool yes;
    if (other > maxx)
        yes = true;
    else
        yes = false;

    if (yes == false)
    {
        cout << maxxid;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
        {
            cout << i << " ";
        }
        if (i == maxxid && a[i] > 1 && use)
        {
            cout << i << " ";
        }
    }
}