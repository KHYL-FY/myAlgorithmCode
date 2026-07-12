#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "请输入n的值（n<=20）: ";
    cin >> n;

    if (n < 1 || n > 20)
    {
        cout << "输入的n值不符合要求！" << endl;
        return 1;
    }

    int f1 = 1, f2 = 1; // 前两项
    int sum = 0;        // 总和

    if (n == 1)
    {
        sum = f1;
        cout << "数列前1项和为: " << sum << endl;
        return 0;
    }

    // n >= 2 时
    sum = f1 + f2; // 前两项和
    cout << "数列: " << f1 << " " << f2 << " ";

    for (int i = 3; i <= n; i++)
    {
        int f3 = f1 + f2; // 计算下一项
        cout << f3 << " ";
        sum += f3;
        f1 = f2;
        f2 = f3;
    }

    cout << endl;
    cout << "数列前" << n << "项和为: " << sum << endl;

    return 0;
}