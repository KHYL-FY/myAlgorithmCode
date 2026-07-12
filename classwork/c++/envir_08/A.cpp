#include <iostream>

using namespace std;

// 基类Base

class Base
{

public:
    Base(double _h);

    double get_h();

    virtual void disp();

private:
    double h;
};

Base::Base(double _h)
{

    h = _h;
}

double Base::get_h()
{

    return h;
}

void Base::disp()
{

    cout << "调用base类disp()函数";
}

/****************************************************/

class Cuboid : public Base
{
private:
    double a, b;

public:
    Cuboid(double _a, double _b, double _h) : Base(_h), a(_a), b(_b)
    {
    }

    double get_a()
    {
        return a;
    }
    double get_b()
    {
        return b;
    }
    void disp()
    {
        cout << "Cuboid体积:" << a * b * get_h() << endl;
    }
};

/****************************************************/

// 派生类Cylinder

class Cylinder : public Base
{

public:
    Cylinder(double _h, double _r);

    virtual void disp();

private:
    double r;
};

Cylinder::Cylinder(double _h, double _r) : Base(_h)
{

    r = _r;
}

void Cylinder::disp()
{

    cout << "Cylinder体积:" << 3.14159 * r * r * get_h() << endl;
}

int main()
{

    Cuboid cuboid(2, 3, 3);

    Base *pc = &cuboid;

    pc->disp();

    Cylinder cylinder(2, 3);

    Base *py = &cylinder;

    py->disp();

    return 0;
}