// 从两头开始一个个判断是否相同即可
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a; // 使用c++自带的string变量

    cin >> a; // c++ cin输入

    int right_pointer = a.length() - 1; // 右下标
    // a.length()获取字符串a的长度  -1是因为数组从0开始
    int left_pointer = 0; // 左下标

    while (right_pointer >= left_pointer) // 循环  在满足 右下标 >= 左下标 的时候循环进行判断
    {
        if (a[right_pointer] != a[left_pointer]) // 如果发现不同直接输出"no"并结束程序
        {
            cout << "no";
            return 0;
        }
        left_pointer++;  // 将左下标+1
        right_pointer--; // 将右下标-1
    }

    cout << "yes"; // 如果循环结束仍未发现不同输出"yes"
}