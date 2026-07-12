#include <iostream>

using namespace std;

int main()
{
    int rabbit, chicken;
    int n, m;
    cout << "input n,m:";
    cin >> n >> m;

    rabbit = m / 2 - n;
    chicken = n - rabbit;

    cout << "鸡:" << chicken << ",兔:" << rabbit;
}