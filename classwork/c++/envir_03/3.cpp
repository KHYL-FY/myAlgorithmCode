#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int fib1 = 0, fib2 = 1, fib3 = 0;

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            fib3 = fib1 + fib2;
            cout << setw(5) << fib3;
            fib2 = fib1;
            fib1 = fib3;
        }
        cout << endl;
    }
}