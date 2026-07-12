#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "输入n(不超过100)" << endl;

    int a[105][105];

    cout << "输入矩阵" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i][j] != 0)
            {
                cout << "不是上三角矩阵" << endl;
                return 0;
            }
        }
    }
    cout << "是上三角矩阵";
}