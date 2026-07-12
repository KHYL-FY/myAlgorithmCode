#include <iostream>

using namespace std;

class Birth
{

public:
    Birth(int year, int month, int day);

    void show();

private:
    int _year;

    int _month;

    int _day;
};

Birth::Birth(int year, int month, int day) : _year(year), _month(month), _day(day)
{

    cout << "Birth类构造函数" << endl;
}

void Birth::show()
{

    cout << "出生日期:" << _year << "-" << _month << "-" << _day << endl;
}

/***********************************************/

// 定义学生类Student

/***************************************************/
class Student
{
public:
    Student(string cin_name, int cin_id, int y, int m, int d) : name(cin_name), id(cin_id),bir(y, m, d) 
    {
        cout << "Student类构造函数" << endl;
    }
    void show()
    {
        cout << "姓名:" << name << endl;
        cout << "学号:" << id << endl;
        bir.show();
    }

private:
    string name;
    int id;
    Birth bir;
};

int main()
{

    Student stu("lili", 10002, 2000, 1, 1); // 创建学生对象stu

    stu.show(); // 显示学生信息

    return 0;
}