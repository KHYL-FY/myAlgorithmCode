#include <iostream>

using namespace std;

int main()
{
    int x, y;

    cin >> x >> y;

    x *= 9;
    y *= 16;
    if (x == y)
        cout << "Yes";
    else
        cout << "No";
}