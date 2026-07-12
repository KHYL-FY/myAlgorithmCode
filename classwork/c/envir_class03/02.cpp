#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double delta, x1, x2;
    double a, b, c;

    cin >> a >> b >> c;

    delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        cout << "无实数解";
        return 0;
    }
    else
    {
        x1 = (-b + sqrt(delta)) / 2.0 * a;
        x2 = (-b - sqrt(delta)) / 2.0 * a;
        cout << x1 << " " << x2;
    }
}