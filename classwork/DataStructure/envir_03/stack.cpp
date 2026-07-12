#include <iostream>

#define ERROR -1
#define OK 0
typedef char SqType;
class stack
{
private:
    const int MAX = 100001;
    struct
    {
        SqType *back;
        SqType *top;
        int maxSize = 0;
    } SqStack;

public:
    int InitStack()
    {
        SqStack.back = new SqType[MAX];
        if (!SqStack.back)
            return ERROR;
        SqStack.maxSize = MAX;
        SqStack.top = SqStack.back;
        return OK;
    }
    SqType push(SqType e)
    {
        if (SqStack.top - SqStack.back == SqStack.maxSize)
            return ERROR;

        *(SqStack.top++) = e;

        return OK;
    }
    int pop(SqType &e)
    {
        if (SqStack.back == SqStack.top)
            return ERROR;

        e = *(--SqStack.top);

        return OK;
    }
    SqType GetElem()
    {
        if (SqStack.top != SqStack.back)
            return *(SqStack.top - 1);
        else
            return ERROR;
    }
    SqType back()
    {
        if (SqStack.top != SqStack.back)
            return *SqStack.back;
        else
            return ERROR;
    }
    ~stack()
    {
        SqType *p = SqStack.top;
        while (SqStack.top != SqStack.back)
        {
            SqStack.top--;
            delete p;
            p = SqStack.top;
        }
    }
};
int main()
{
    stack a;
    a.InitStack();
    for (int i = 1; i <= 5; i++)
    {
        char num = '0' + i;
        a.push(num);
        std::cout << "成功将" << i << "放入栈" << std::endl;
    }
    SqType e;
    e = a.GetElem();
    std::cout << "栈顶为" << e << std::endl;

    e = a.back();
    std::cout << "栈底为" << e << std::endl;


    a.pop(e);
    std::cout << "成功将" << e << "弹出栈" << std::endl;

    e = a.GetElem();
    std::cout << "栈顶为" << e << std::endl;

    e = a.back();
    std::cout << "栈底为" << e << std::endl;

    return 0;
}