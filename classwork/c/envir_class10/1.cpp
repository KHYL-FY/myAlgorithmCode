#include <iostream>

using namespace std;

void swapp(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;

    return;
}
int main()
{
    int a, b;
    int *x = &a, *y = &b;

    cin >> a >> b;

    cout << a << " " << b << endl;
    swapp(x, y);

    cout << a << " " << b << endl;
}