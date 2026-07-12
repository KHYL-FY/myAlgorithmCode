#include <iostream>

using namespace std;

class Stock
{
public:
    double hprice, lprice, begin, end;
    Stock(double a, double b, double c, double d) : hprice(a), lprice(b), begin(c), end(d) {}
    double diff()
    {
        return end - begin;
    }
};
int main()
{
    Stock a(20, 10, 20, 10);
    cout << a.diff();
}