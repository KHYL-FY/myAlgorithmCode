#include <iostream>

using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;

    if (m % 2 == 0)
        if (n <= m / 2)
            cout << "Yes";
        else
            cout << "No";
    else if (n <= m / 2 + 1)
        cout << "Yes";
        else
            cout << "No";

    return 0;
}