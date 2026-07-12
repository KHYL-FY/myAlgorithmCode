#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a == 1 && b == 7)
        cout << "Yes";
    else if (a == 3 && b == 3)
        cout << "Yes";
    else if (a == 5 && b == 5)
        cout << "Yes";
    else if (a == 7 && b == 7)
        cout << "Yes";
    else if (a == 9 && b == 9)
        cout << "Yes";
    else
        cout << "No";
}