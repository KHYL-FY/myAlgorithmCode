#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[6];
    int maxNum = -1, minNum = 1000001;
    int maxp, minp;
    for (int i = 1; i <= 5; i++)
    {
        cin >> a[i];
        if (maxNum < a[i])
        {
            maxNum = a[i];
            maxp = i;
        }
        if (minNum > a[i])
        {
            minNum = a[i];
            minp = i;
        }
    }
    swap(a[maxp], a[1]);
    // swap(a[minp], a[5]);

    // cout << maxNum << minNum;
    for (int i = 1; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
}