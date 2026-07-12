#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double pi_4 = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        pi_4 += pow(-1, i + 1) * (1.0 / (2 * (double)i - 1));
    }
    cout << pi_4 * 4.0;
}