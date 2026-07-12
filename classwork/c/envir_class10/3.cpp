#include <iostream>

using namespace std;

void fun(int *a, int n, int *odd, int *even)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
        {
            *even += *(a + i);
        }
        else
        {
            *odd += *(a + i);
        }
    }
}
int main()
{
    int a[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int odd = 0, even = 0;

    fun(&a[0], n, &odd, &even);

    cout << "奇数和:" << odd << endl
         << "偶数和:" << even;
}