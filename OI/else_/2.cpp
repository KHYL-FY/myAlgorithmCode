#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    int a[x + 5];
    for (int i = 1; i <= x; i++)
    {
        cin >> a[i];
        if (a[i] > z)
            ans += 3;
    }
    cout << ans;
}