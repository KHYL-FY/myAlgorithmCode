#include <iostream>

#include <cstring>

using namespace std;

class Student
{

private:
    int _id;

    string _name;

    char *_addr;

public:
    Student(int id, string name, const char *addr);

    Student();

    Student &operator=(Student &stu);

    void show();
};

Student::Student() {}

Student::Student(int id, string name, const char *addr)
{

    /******************************************/
    _id = id;
    _name = name;
    int len = strlen(addr);
    _addr = new char[len + 1];
    strcpy(_addr, addr);
    /******************************************/
}

Student &Student::operator=(Student &stu)
{

    // 注意深拷贝

    /******************************************/
    if (this == &stu)
        return *this;

    // cout << 666;

    _addr = new char[strlen(stu._addr) + 1];
    strcpy(_addr, stu._addr);

    _id = stu._id;
    _name = stu._name;

    return *this;
    /******************************************/
}

void Student::show()
{

    cout << "学号:" << _id << endl;

    cout << "姓名:" << _name << endl;

    cout << "住址:" << _addr << endl;
}

int main()
{

    Student stu2, stu1(10001, "zhangsan", "luoyang");

    stu1.show();

    stu2 = stu1;

    stu2.show();

    return 0;
}
