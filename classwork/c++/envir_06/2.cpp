#include <iostream>

using namespace std;

class Person
{

private:
    string _id;

    string _name;

    string _sex;

public:
    Person(string id, string name, string sex);

    void show();
};

Person::Person(string id, string name, string sex)
{

    _id = id;

    _name = name;

    _sex = sex;
}

void Person::show()
{

    cout << "编号:" << _id << endl;

    cout << "姓名:" << _name << endl;

    cout << "性别:" << _sex << endl;
}

class Date
{

public:
    Date(int y, int m, int d)
    {

        _year = y;

        _month = m;

        _day = d;
    }

    void display()
    {

        cout << "出生日期:" << _year << "." << _month << "." << _day << endl;
    }

protected:
    int _month, _day, _year;
};

class Employee : public Person
{

public:
    Employee(string id, string name, string sex, int y, int m, int d, string dept, string duty);

    void show();

private:
    Date date;

    string _dept;

    string _duty;
};

/*************************************************************/
Employee::Employee(string id, string name, string sex, int y, int m, int d, string dept, string duty) : Person(id, name, sex), date(y, m, d), _dept(dept), _duty(duty)
{
}
void Employee::show()
{
    Person::show();
    date.display();
    cout << "部门:" << _dept << endl
         << "职务:" << _duty;
}
/*************************************************************/

int main()
{

    Employee employee("10001", "杨萍", "女", 1990, 9, 29, "团委", "团委书记");

    employee.show();

    return 0;
}