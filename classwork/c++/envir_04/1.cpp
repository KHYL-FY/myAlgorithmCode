#include <iostream>

#include <cstring>

using namespace std;

class Student
{

public:
    Student(int id, string name, char *addr);

    Student(const Student &other);

    ~Student();

    void show();

private:
    int _id;

    string _name;

    char *_addr;
};

Student::Student(int id, string name, char *addr)
{

    cout << "调用构造函数" << endl;

    /************************************************/

    /************************************************/
}

Student::Student(const Student &another)
{

    cout << "调用拷贝构造函数" << endl;

    /************************************************/

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

    char *p = "beijing";

    Student stuA(123456, "zhangsan", p);

    cout << "stuA:";

    stuA.show();

    Student stuB(stuA); // 使用sheepA初始化新对象sheepB

    cout << "stuB:";

    stuB.show();

    return 0;
}