#include <iostream>
#include <cmath>
using namespace std;

bool ifprim(int num)
{
    if (num == 1)
        return false;
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
    int n;
    cin >> n;

    if (ifprim(n))
    {
        cout << "YES";
    }
    else
        cout << "NO";
}