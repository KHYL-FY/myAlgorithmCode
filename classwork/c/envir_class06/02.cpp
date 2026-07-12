#include <iostream>

using namespace std;

double jiecheng(int n)
{
    double ans = 1;

    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    double e = 1;
    for (int i = 1; i <= 20; i++)
    {
        e += 1.0 / (jiecheng(i));
    }
    cout << e;
}