#include <iostream>
using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1

template <typename T>
class LinkQueue
{
private:
    struct QNode
    {
        T data;
        QNode *next;
    };
    QNode *front;
    QNode *rear;

public:
    LinkQueue()
    {
        front = rear = new QNode;
        front->next = nullptr;
    }

    bool empty()
    {
        return front == rear;
    }

    int push(T e)
    {
        QNode *s = new QNode;
        s->data = e;
        s->next = nullptr;
        rear->next = s;
        rear = s;
        return OK;
    }

    int pop(T &e)
    {
        if (empty())
            return ERROR;
        QNode *p = front->next;
        e = p->data;
        front->next = p->next;
        if (rear == p)
            rear = front;
        delete p;
        return OK;
    }

    int print()
    {
        if (empty())
            return ERROR;
        QNode *p = front->next;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
        return OK;
    }

    ~LinkQueue()
    {
        while (front)
        {
            QNode *p = front;
            front = front->next;
            delete p;
        }
    }
};

int main()
{
    LinkQueue<int> Q;
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int len = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < len; i++)
    {
        Q.push(a[i]);
    }

    cout << "链队元素：";
    Q.print();

    int e;
    Q.pop(e);
    cout << "第一个出队：" << e << endl;
    Q.pop(e);
    cout << "第二个出队：" << e << endl;

    cout << "剩余元素：";
    Q.print();
    return 0;
}