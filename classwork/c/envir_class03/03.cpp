#include <iostream>

using namespace std;

int main()
{
    float a, b;
    int azhengshu, bzhengshu;

    cin >> a >> b;

    azhengshu = a;
    bzhengshu = b;

    a = a - azhengshu + bzhengshu;
    b = b - bzhengshu + azhengshu;

    cout << a << " " << b;
}