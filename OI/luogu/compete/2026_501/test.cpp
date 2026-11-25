#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a[n];
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        if (k >= 97 && k <= 122)
        {
            k = k - 32;
            a[i] = k;
        }
        else if (k >= 65 && k <= 90)
        {
            k = k + 32;
            a[i] = k;
        }
        else
        {
            a[i] = '*';
        }
    }
    cout << a;
}