#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int sum = 0;
    bool flag = true;
    for (int i = 100; i <= 200; i++)
    {
        flag = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i << " ";
            sum++;
        }
    }
    cout << endl;
    cout << sum;
}