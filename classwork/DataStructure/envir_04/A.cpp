#include <iostream>

using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1

template <typename QueueType>
class queue
{

private:
    const int MAXSIZE = 1e4 + 1;

    QueueType *data;

public:
    int front, back;

    queue()
    {
        // cout << "调用构造函数";
        data = new QueueType[MAXSIZE + 5];
        front = back = 0;
    }
    size_t size()
    {
        return (back - front + MAXSIZE) % MAXSIZE;
    }
    QueueType push(QueueType e)
    {
        if ((back + 1) % MAXSIZE == front)
            return ERROR;
        data[back] = e;
        back = (back + 1) % MAXSIZE;
        return e;
    }
    QueueType pop()
    {
        if (front == back)
            return ERROR;
        QueueType e = data[front];
        front = (front + 1) % MAXSIZE;

        return e;
    }
    int print()
    {
        int p = front;
        if (front == back)
            return ERROR;

        while (p != back)
        {
            cout << data[p] << " ";
            p = (p + 1) % MAXSIZE;
        }
        cout << endl;

        return OK;
    }
    ~queue()
    {
        delete[] data;
    }
};
int main()
{
    queue<int> q;

    cout << "循环队列长度=" << q.size() << endl;

    for (int i = 1; i <= 6; i++)
    {
        q.push(i * 10);
    }

    cout << "循环队列长度=" << q.size() << endl;

    cout << "从队头到队尾依次输出循环队列中的数据：" << endl;
    q.print();

    int e;
    e = q.pop();
    cout << "第一个出队的元素为：" << e << endl;

    e = q.pop();
    cout << "第二个出队的元素为：" << e << endl;

    cout << "循环队列长度=" << q.size() << endl;

    cout << "从队头到队尾依次输出循环队列中的数据：" << endl;
    q.print();

    return 0;
}