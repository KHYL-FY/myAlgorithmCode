#include <iostream>

using namespace std;

int main()
{
    const int N = 5;
    int a[5];
    int numin = 1e8;
    int p = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        if (a[i] < numin)
        {
            numin = a[i];
            p = i;
        }
    }

    cout << "最小值为" << numin << endl
         << "其下标为" << p;
}