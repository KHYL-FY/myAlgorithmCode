#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    if (num % 3 == 0 && num % 5 == 0 && num % 7 == 0)
    {
        cout << "YES";
    }
    else
        cout << "NO";
}