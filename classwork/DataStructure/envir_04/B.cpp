#include <iostream>
#include <cstring>
using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1

struct Person
{
    char name[20];
    char sex;
};

template <typename QueueType>
class Queue
{
private:
    const int MAXSIZE = 100;
    QueueType *data;

public:
    int front, back;

    Queue()
    {
        data = new QueueType[MAXSIZE];
        front = back = 0;
    }

    size_t size()
    {
        return (back - front + MAXSIZE) % MAXSIZE;
    }

    int push(QueueType e)
    {
        if ((back + 1) % MAXSIZE == front)
            return ERROR;
        data[back] = e;
        back = (back + 1) % MAXSIZE;
        return OK;
    }

    int pop(QueueType &e)
    {
        if (front == back)
            return ERROR;
        e = data[front];
        front = (front + 1) % MAXSIZE;
        return OK;
    }

    bool empty()
    {
        return front == back;
    }

    int print()
    {
        int p = front;
        if (front == back)
            return ERROR;
        while (p != back)
        {
            cout << data[p].name << " ";
            p = (p + 1) % MAXSIZE;
        }
        cout << endl;
        return OK;
    }

    ~Queue()
    {
        delete[] data;
    }
};

void DancePartner(Person dancer[], int num)
{
    Queue<Person> Mqueue, Fqueue;

    for (int i = 0; i < num; i++)
    {
        if (dancer[i].sex == 'F')
            Fqueue.push(dancer[i]);
        else
            Mqueue.push(dancer[i]);
    }

    cout << "跳舞的女士：";
    Fqueue.print();
    cout << "跳舞的男士：";
    Mqueue.print();

    cout << "\n舞伴配对结果：" << endl;
    Person m, f;
    while (!Mqueue.empty() && !Fqueue.empty())
    {
        Fqueue.pop(f);
        Mqueue.pop(m);
        cout << f.name << " —— " << m.name << endl;
    }

    if (!Fqueue.empty())
    {
        Person first;
        Fqueue.pop(first);
        cout << "\n下一轮首位等待女士：" << first.name << endl;
    }
    if (!Mqueue.empty())
    {
        Person first;
        Mqueue.pop(first);
        cout << "\n下一轮首位等待男士：" << first.name << endl;
    }
}

int main()
{
    Person dancer[10] = {
        {"李雷", 'M'}, {"韩梅梅", 'F'}, {"小明", 'M'}, {"小红", 'F'}, {"王子", 'M'}, {"张小帅", 'M'}, {"公主", 'F'}, {"王小辉", 'M'}, {"刘小英", 'F'}, {"李小刚", 'M'}};
    DancePartner(dancer, 10);
    return 0;
}