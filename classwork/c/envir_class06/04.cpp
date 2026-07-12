#include <iostream>

using namespace std;

int main()
{
    int years = 0;

    double yuan = 1000;

    while (yuan < 1500)
    {
        yuan *= 1.15;
        years++;
    }

    cout << years;
}