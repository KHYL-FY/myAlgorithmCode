#include <iostream>
#include <cmath>
using namespace std;

bool prime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{

    for (int i = 2; i <= 1000; i++)
    {
        if (prime(i))
        {
            cout << i << endl;
        }
    }
}