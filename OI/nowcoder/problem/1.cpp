#include <iostream>

using namespace std;

int main()
{
    string a;
    string b;
    char zimu;
    while (scanf("%s", &a[0]) != EOF)
    {
        zimu = a[0];
        if (zimu <= 'z' && zimu >= 'a')
        {
            zimu -= ('a' - 'A');
        }
        b += zimu;
    }
    cout << b;
    return 0;
}