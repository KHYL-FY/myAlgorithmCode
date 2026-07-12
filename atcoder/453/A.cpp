#include <iostream>

using namespace std;

int main()
{
    string a;
    int n;
    cin >> n >> a;
    int i = 0;
    while (a[i] == 'o')
        i++;

    for (int j = i; j < n;j++)
        cout << a[j];
}