#include <iostream>

#define ERROR -1
#define OK 0
typedef char SqType;
class stack
{
private:
    static const int MAX = 2000001;
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
    void pop(SqType e = ' ')
    {
        --SqStack.top;

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
    void clear()
    {
        SqStack.top = SqStack.back;
    }
    ~stack()
    {
        delete[] SqStack.back;
    }
};

int main()
{
    stack a;
    a.InitStack();

    bool flag = true;

    std::string ch;

    int t;
    std::cin >> t;

    while (t--)
    {
        flag = true;
        a.clear();
        std::cin >> ch;
        for (int i = 0; i < ch.length(); i++)
        {
            switch (ch[i])
            {
            case '{':
            case '[':
            case '(':
                a.push(ch[i]);
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
            case '}':
                if (!a.empty() && a.top() == '{')
                    a.pop();
                else
                    flag = false;
                break;
            }
        }
        if (a.empty() && flag)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}
