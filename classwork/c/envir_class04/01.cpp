#include <iostream>

using namespace std;

int main()
{
    char a;
    a = getchar();
    if (a < 32)
    {
        cout << "控制字符";
    }
    else if (a >= '0' && a <= '9')
    {
        cout << "数字字符";
    }
    else if (a >= 'a' && a <= 'z')
    {
        cout << "小写字符";
    }
    else if (a >= 'A' && a <= 'Z')
    {
        cout << "大写字符";
    }
    else{
        cout << "其他字符";
    }
}