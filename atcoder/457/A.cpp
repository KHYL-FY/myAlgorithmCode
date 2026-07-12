#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[105];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int p;
    cin >> p;
    cout << a[p];
}