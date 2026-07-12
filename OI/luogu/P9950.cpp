#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++)
    {

        if (a[i] == b[i] && i > 0)
        {
            if (a[i - 1] != b[i - 1])
                ans++;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] == 'G' && b[i] == 'H')
    //         c[i] = 1;
    //     if (a[i] == 'H' && b[i] == 'G')
    //         c[i] = 1;
    //     if ((a[i] == 'H' && b[i] == 'H') || (a[i] == 'G' && b[i] == 'G'))
    //         c[i] = 3;
    // }
    // int pointer = c[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if (c[i] == 3)
    //     {
    //         if (pointer != 3)
    //         {
    //             pointer = 3;
    //             ans++;
    //         }
    //         continue;
    //     }
    //     if (c[i] == 1)
    //     {
    //         if (pointer == 3)
    //         {
    //             pointer = 1;
    //         }
    //         continue;
    //     }
    // }
    cout << ans;
}