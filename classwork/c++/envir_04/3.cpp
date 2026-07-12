#include <iostream>

#include <cmath>

using namespace std;

class Point
{

    friend float dis(Point &p1, Point &p2);

public:
    Point(float x, float y);

    ~Point();

private:
    float _x;

    float _y;
};

Point::Point(float x = 0, float y = 0) : _x(x), _y(y)
{

    cout << "初始化坐标点" << endl;
}

Point::~Point() {}

float dis(Point &p1, Point &p2)
{

    /**************************************************/
    return sqrt(pow(p1._x - p2._x, 2) + pow(p1._y - p2._y, 2));
    /**************************************************/
}

int main()
{

    Point p1(5, 5);

    Point p2(10, 10);

    float distance = dis(p1, p2);

    cout << "两点间距离是:" << distance << endl;

    return 0;
}