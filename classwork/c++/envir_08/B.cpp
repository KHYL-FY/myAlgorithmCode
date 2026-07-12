#include <iostream>

using namespace std;

class Container
{ // 声明抽象类container

protected:
    double radius;

public:
    Container(double _radius)
    { // 抽象类container的构造函数

        radius = _radius;
    }

    virtual double surface_area() = 0; // 纯虚函数surface_area

    virtual double volume() = 0; // 纯虚函数volume
};

/****************************************************/

// 派生类sphere  pi=3.14159   s=4*pi*r*r   v=4/3*pi*r*r*r
class Sphere : public Container
{
private:
    constexpr static double pi = 3.14159;

public:
    Sphere(double _radicus) : Container(_radicus) {}

    double volume()
    {
        return  4.0 / 3.0 * pi * radius * radius * radius;
    }

    double surface_area()
    {
        return 4 * pi * radius * radius;
    }
};
/****************************************************/

// 派生类Cylinder

class Cylinder : public Container
{

public:
    Cylinder(double _radius, double _height);

    double surface_area();

    double volume();

private:
    double height;
};

Cylinder::Cylinder(double _radius, double _height) : Container(_radius)
{

    height = _height;
}

double Cylinder::surface_area()
{

    return 2 * 3.14159 * radius * height + 2 * 3.14159 * radius * radius;
}

double Cylinder::volume()
{

    return 3.14159 * radius * radius * height;
    ;
}

int main()
{

    Sphere sphere(2);

    cout << "球体表面积:" << sphere.surface_area() << endl;

    cout << "球体体积:" << sphere.volume() << endl;

    Cylinder Cylinder(2, 3);

    cout << "圆柱体表面积:" << Cylinder.surface_area() << endl;

    cout << "圆柱体体积:" << Cylinder.volume() << endl;
}