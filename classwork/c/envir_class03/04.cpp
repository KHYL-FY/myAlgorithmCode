#include <iostream>

using namespace std;

int main()
{
    int x, y, f, h;
    cin >> h >> f;

    x = 1.0 / 2 * (4 * h - f);
    y = 1.0 / 2 * (f - 2 * h);

    cout << x << " " << y;
    return 0;
}