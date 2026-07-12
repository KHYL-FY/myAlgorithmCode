#include <iostream>
using namespace std;

#define ERROR -1
#define OK 0
typedef char SqType;

class LinkStack
{
private:
    struct StackNode
    {
        SqType data;
        StackNode *next;
    };
    StackNode *top;

public:
    LinkStack()
    {
        top = NULL;
    }

    int push(SqType e)
    {
        StackNode *s = new StackNode;
        if (!s)
            return ERROR;
        s->data = e;
        s->next = top;
        top = s;
        return OK;
    }

    int pop(SqType &e)
    {
        if (top == NULL)
            return ERROR;
        StackNode *p = top;
        e = top->data;
        top = top->next;
        delete p;
        return OK;
    }

    SqType GetElem()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            return ERROR;
        }
    }

    ~LinkStack()
    {
        StackNode *p;
        while (top != NULL)
        {
            p = top;
            top = top->next;
            delete p;
        }
    }
};

int main()
{
    LinkStack a;

    for (int i = 1; i <= 5; i++)
    {
        char num = '0' + i;
        a.push(num);
        cout << "成功将" << i << "放入栈" << endl;
    }

    SqType e;
    e = a.GetElem();
    cout << "栈顶为" << e << endl;

    a.pop(e);
    cout << "成功将" << e << "弹出栈" << endl;

    e = a.GetElem();
    cout << "栈顶为" << e << endl;

    return 0;
}