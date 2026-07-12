#include <iostream>

using namespace std;

bool leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}
int main()
{
    int year = 2000;
    for (; year <= 3000; year++)
    {
        if (leap(year))
        {
            cout << year << endl;
        }
    }

    return 0;
}