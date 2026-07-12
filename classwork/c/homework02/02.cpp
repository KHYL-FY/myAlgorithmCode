#include <iostream>
using namespace std;

int main()
{
    int a[11];

    for (int i = 1; i <= 10; i++)
    {
        cin >> a[i];
    }
    int ans = a[1];
    int pointer = 1;

    for (int i = 1; i <= 10; i++)
    {
        if (a[i] < ans)
        {
            ans = a[i];
            pointer = i;
        }
    }

    cout << "最小值及其下标为:" << ans << " " << pointer;
}