#include <iostream>
#include <iomanip>
using namespace std;
const double pi = 3.14159;
class area
{
public:
    void user_choice();
    void cin_data();
    void calgulate();
    void again();
    bool bool_again = true;

private:
    string choice;
    double ans = 0;
    double r, a, b;
    string again_choice;
};
void area::user_choice()
{
    cout << "请输入要计算面积的图形" << endl;
    cout << "1.圆形" << endl
         << "2.长方形" << endl
         << "3.正方形" << endl;

    while (cin >> choice)
    {
        if (choice == "圆形" || choice == "长方形" || choice == "正方形")
            break;
        else
            cout << "输入非法,请重新输入" << endl;
    }
}
void area::cin_data()
{
    if (choice == "圆形")
    {
        double local_r = 0;
        cout << "请输入圆形的半径: " << endl;

        cin >> local_r;

        if (local_r >= 0)
        {
            r = local_r;
        }
    }
    else if (choice == "长方形")
    {
        double local_a = 0, local_b = 0;

        cout << "请输入长方形的长与宽: " << endl;
        cin >> local_a >> local_b;

        if (local_a >= 0 && local_b >= 0)
        {
            a = local_a, b = local_b;
        }
    }
    else if (choice == "正方形")
    {
        double local_a;
        cout << "请输入正方形的边长: " << endl;
        cin >> local_a;
        if (local_a >= 0)
        {
            a = local_a;
        }
        else
            cout << "输入非法,请重新输入" << endl;
    }
}
void area::calgulate()
{

    if (choice == "圆形")
    {
        ans = pi * r * r;
    }
    else if (choice == "长方形")
    {
        ans = a * b;
    }
    else if (choice == "正方形")
    {
        ans = a * a;
    }
    cout << "计算结果为: " << setprecision(2) << fixed << ans << endl;
}
void area::again()
{
    cout << "是否继续?" << endl
         << "1.是" << endl
         << "2.否" << endl;
    while (cin >> again_choice)
    {
        if (again_choice == "是")
            break;
        else if (again_choice == "否")
        {
            bool_again = false;
            cout << "程序结束" << endl;
            break;
        }
        else
        {
            cout << "输入非法,请重新输入" << endl;
        }
    }
}
int main()
{
    area a;
    while (a.bool_again)
    {
        a.user_choice();
        a.cin_data();
        a.calgulate();
        a.again();
    }

    return 0;
}