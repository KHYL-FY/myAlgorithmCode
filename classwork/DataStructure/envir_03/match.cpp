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
    SqType pop(SqType e = ' ')
    {
        if (SqStack.back == SqStack.top)
            return ' ';

        e = *(--SqStack.top);

        return e;
    }
    SqType top()
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
    bool empty()
    {
        if (SqStack.back == SqStack.top)
            return true;
        else
            return false;
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

    bool flag = true;
    char ch;

    std::cout << "请输入括号(输入 # 来终止)" << std::endl;
    std::cin >> ch;
    while (ch != '#' && flag)
    {
        switch (ch)
        {
        case '[':
        case '(':
            a.push(ch);
            break;

        case ')':
            if (!a.empty() && a.top() == '(')
                a.pop();
            else
                flag = false;
            break;
        case ']':
            if (!a.empty() && a.top() == '[')
                a.pop();
            else
                flag = false;
            break;
        }
        std::cin >> ch;
    }
    if (a.empty() && flag)
        std::cout << "匹配成功" << std::endl;
    else
        std::cout << "匹配失败" << std::endl;
}