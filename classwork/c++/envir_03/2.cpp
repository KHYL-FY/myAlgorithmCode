#include <iostream>

#include <cstring>

using namespace std;

class Student
{

public:
    Student(int id, string name, const char *addr);

    Student(const Student &other);

    ~Student();

    void show();

private:
    int _id;

    string _name;

    char *_addr;
};

Student::Student(int id, string name,const char *addr)
{

    cout << "调用构造函数" << endl;

    /************************************************/
    _id = id;
    _name = name;
    _addr = new char[strlen(addr) + 1];
    strcpy(_addr, addr);
    /************************************************/
}

Student::Student(const Student &another)
{

    cout << "调用拷贝构造函数" << endl;

    /************************************************/
    _id = another._id;
    _name = another._name;
    _addr = new char[strlen(another._addr) + 1];
    strcpy(_addr, another._addr);
    /************************************************/
}

void Student::show()
{

    cout << _id << " " << _name << " " << _addr << endl;
}

Student::~Student()
{

    cout << "调用析构函数" << endl;

    if (_addr != NULL)

        delete[] _addr;
}

int main()
{

    const char *p = "beijing";

    Student stuA(123456, "zhangsan", p);

    cout << "stuA:";

    stuA.show();

    Student stuB(stuA); // 使用sheepA初始化新对象sheepB

    cout << "stuB:";

    stuB.show();

    return 0;
}