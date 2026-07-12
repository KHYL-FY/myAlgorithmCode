#include <bits/stdc++.h>

using namespace std;

class Cylinder
{
public:
    Cylinder(double r, double h);
    double vol();

private:
    double pr, ph;
    const double pi = 3.14159;
};
Cylinder::Cylinder(double r, double h)
{
    //cin >> r >> h;
    pr = r;
    ph = h;
    return;
}
double Cylinder::vol()
{
    return pi * pr * pr * ph;
}
int main()
{

    double r, h;

    cout << "input r,h:";

    cin >> r >> h;

    Cylinder cy(r, h);

    cout << "v=" << cy.vol() << endl;

    return 0;
}