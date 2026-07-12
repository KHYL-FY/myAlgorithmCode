#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;
    float area, p;
    cout << "请输入正确的三角形三边的边长"<<endl;
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "你输入的不是正确的三角形三边边长";
        return 0;
    }
    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << area;
}