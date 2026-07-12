#include <iostream>

using namespace std;

class shape
{

protected:
    int x, y; // 坐标

public:
    shape(int x = 0, int y = 0) : x(x), y(y) {}

    int getArea()
    {

        cout << "shape::getArea() 基类面积计算" << endl;

        return 0;
    }
};

// 长方体底面：虚继承 矩形 + 正方形
class Rectangle : public virtual shape
{
protected:
    int h, w;

public:
    Rectangle(int _h, int _w) : h(_h), w(_w) {}
    int getArea()
    {

        cout << "Rectangle::getArea() 矩形面积 = " << h * w << endl;

        return 0;
    }
};
class Square : public virtual shape
{
protected:
    int a;

public:
    Square(int _a) : a(_a) {}
    int getArea()
    {

        cout << "Square::getArea() 正方形面积 = " << a * a << endl;

        return 0;
    }
};
class CuboidBase : public virtual Rectangle,
                   public virtual Square
{

private:
    int height;

public:
    CuboidBase(int h, int w, int l) : Rectangle(h, w), Square(h), height(l) {}

    // 按矩形底面去算

    int calcVolByRect()
    {
        Rectangle::getArea();
        return a * a * height;
    }

    // 按正方形算体积

    int calcVolBySquare()
    {
        Square::getArea();

        return h * w * height;
    }
};

int main()
{

    // 1. 赋值兼容规则：基类指针 指向 派生类对象
    shape *p;
    Rectangle rect(4, 2);
    Square sq(3);
    CuboidBase cub(5, 5, 10);
    // 指针指向矩形
    p = &rect;
    cout << "指针指向矩形：";
    p->getArea();

    // 指针指向正方形
    p = &sq;
    cout << "指针指向正方形：";
    p->getArea();

    // 指针指向长方体底面
    p = &cub;
    cout << "指针指向长方体：";
    p->getArea(); // 静态绑定

    // 长方体双规则计算
    cout << "======= 长方体体积计算 =======" << endl;
    cout << "按矩形算体积：" << cub.calcVolByRect() << endl;
    cout << "按正方形算体积：" << cub.calcVolBySquare() << endl;

    return 0;
}