#include <iostream>
#include <iomanip>
using namespace std;

class Complex
{

private:
    double real;

    double imag;

public:
    Complex(double x = 0, double y = 0) : real(x), imag(y) {}

    void show() const; // 输出数据

    friend Complex operator+(const Complex &a1, const Complex &a2); // 重载为类的友元函数

    friend Complex operator-(const Complex &a1, const Complex &a2); // 重载为类的友元函数
};

/******************************************************************/
Complex operator+(const Complex &a1, const Complex &a2)
{
    return Complex(a1.real + a2.real, a1.imag + a2.imag);
}

Complex operator-(const Complex &a1, const Complex &a2)
{
    return Complex(a1.real - a2.real, a1.imag - a2.imag);
}
void Complex::show() const
{
    cout << setprecision(2) << real;
    if (imag > 0)
        cout << "+";
    cout << setprecision(2) << imag << "i" << endl;
}
/******************************************************************/

int main()
{

    Complex c1(5.1, 3.4);

    Complex c2(3.6, 5.3);

    Complex c;

    cout << "c1:";

    c1.show();

    cout << "c2:";

    c2.show();

    c = c1 + c2;

    cout << "c1+c2:";

    c.show();

    c = c1 - c2;

    cout << "c1-c2:";

    c.show();

    return 0;
}