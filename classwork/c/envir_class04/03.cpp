#include <iostream>

using namespace std;

int main()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int years, months;

    cin >> years >> months;

    if (((years % 4 == 0 && years % 100 != 0) || years % 400 == 0) && months == 2)
    {
        cout << "29";
    }
    else
    {
        cout << days[months];
    }
}