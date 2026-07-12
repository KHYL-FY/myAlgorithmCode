#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6 - i; j++)
        {
            cout << " ";
        }
        for (int x = 1; x <= i;x++){
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6 - i; j++)
        {
            cout << " ";
        }
        for (int x = 1; x <= i; x++)
        {
            cout << "*";
        }

        for (int x = 1; x < i; x++)
        {
            cout << "*";
        }
        for (int j = 1; j <= 6 - i; j++)
        {
            cout << " ";
        }
        
        cout << endl;
    }
}