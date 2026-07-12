#include <iostream>
using namespace std;

int f[1002][1002];

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> f[i][j];
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }

    cout << f[1][1];
}