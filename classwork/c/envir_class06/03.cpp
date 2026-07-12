#include <iostream>

using namespace std;

int main()
{
    for (int i = 7;; i += 7)
    {
        if (i % 2 == 1 && i % 3 == 2 && i % 5 == 4 && i % 6 == 5)
        {
            cout << i;
            return 0;
        }
    }
}