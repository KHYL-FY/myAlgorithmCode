#include <iostream>
using namespace std;

int main()
{
    int a[7];

    for (int i = 1; i <= 6; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= 6; i++)
    {
        for (int j = i; j <= 6; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = 1; i <= 6; i++)
    {
        cout << a[i] << " ";
    }
}