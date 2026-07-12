#include <iostream>

using namespace std;

class Person
{

private:
    string _id;

    string _name;

    int _age;

public:
    Person(string id, string name, int age);

    void show();
};

Person::Person(string id, string name, int age)
{

    _id = id;

    _name = name;

    _age = age;
}

void Person::show()
{

    cout << "编号:" << _id << endl;

    cout << "姓名:" << _name << endl;

    cout << "年龄:" << _age << endl;
}

// 派生类

class Student : public Person
{

private:
    string _major;

    int _score;

public:
    Student(string id, string name, int age, string major, int score);

    void show();
};

/*********************************************************************/
Student::Student(string id, string name, int age, string major, int score) : Person(id, name, age), _major(major), _score(score)
{
}
void Student::show()
{
    Person::show();
    cout << "专业:" << _major << endl
         << "成绩:" << _score;
}
/*********************************************************************/

int main()
{

    Student stu1("s10001", "zhangsan", 20, "软件工程", 95);

    stu1.show();

    return 0;
}