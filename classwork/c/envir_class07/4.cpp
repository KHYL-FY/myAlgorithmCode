#include <iostream>

using namespace std;

int main()
{

    int a[15] = {10, 34, 5, 23, 1, 76, 65, 48, 101, 19};

    int t;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        cout << a[i] << " ";
    }
}