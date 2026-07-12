#include <iostream>
using namespace std;

int main()
{
    int a[7];

    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    int temp;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
}