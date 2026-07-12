//50分
#include <iostream>
using namespace std;
int main()
{
    int louti[5002];
    louti[1] = 1;
    louti[2] = 2;
    int n;
    cin >> n;
    int q = 3;
    while (q-1 != n)
    {
        louti[q] = louti[q - 1] + louti[q - 2];
        q++;
    }
    cout << louti[n];
}
