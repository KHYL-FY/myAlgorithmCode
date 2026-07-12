#include <iostream>
using namespace std;
int Min(int a, int b, int c)
{
    return a < (b < c ? b : c) ? a : (b < c ? b : c);
}
int Min(int a, int b)
{
    return a < b ? a : b;
}
double Min(double a, double b)
{
    return a < b ? a : b;
}
double Min(double a, double b, double c)
{
    return a < (b < c ? b : c) ? a : (b < c ? b : c);
}
int main()
{
    cout << Min(1, 10, 3) << endl;
    cout << Min(3, 1) << endl;
    cout << Min(3.2, 8.99, 1.2) << endl;
    cout << Min(3.1, 2.5);
}