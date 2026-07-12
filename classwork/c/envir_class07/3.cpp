#include <iostream>

using namespace std;

int main()
{
    char a16[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char ans[101];

    int n;
    cin >> n;

    int p = 1;
    while (n != 0)
    {
        ans[p] = a16[n % 16];
        n /= 16;
        p++;
    }

    for (int i = p; i >= 1; i--)
    {
        cout << ans[i];
    }
}