#include <iostream>

using namespace std;

int main()
{
    // 2541王艺杰
    int n;
    cin >> n;

    string books[101];

    for (int i = 1; i <= n; i++)
    {
        cin >> books[i];
    }

    cout << "请输入要查找的图书名" << endl;
    string findbook;
    cin >> findbook;

    for (int i = 1; i <= n; i++)
    {
        if (findbook == books[i])
        {
            cout << "查找成功";
            return 0;
        }
        else
        {
            cout << "查找失败";
            return 0;
        }
    }
}