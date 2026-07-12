#include <iostream>

#include <cstring>

using namespace std;

class Stock
{
public:
    Stock(string code, int q, double p);
    void print();

private:
    string stockcode;
    int quantity;
    double price;
};
Stock::Stock(string code, int q = 1000, double p = 5.67)
{
    stockcode = code;
    quantity = q;
    price = p;
}
void Stock::print()
{
    cout << "stockcode:" << stockcode << endl;
    cout << "quantity:" << quantity << endl;
    cout << "price:" << price << endl;
}
int main()
{

    Stock s1("60001", 3000, 8.98);

    s1.print();

    Stock s2("60002");

    s2.print();

    return 0;
}