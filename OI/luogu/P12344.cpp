#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;

    int len = a.length();
    char mchar = 0;
    for (int i = 0; i < len; i++)
    {
        mchar = max(mchar, a[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if (a[i] == mchar)
            cout << a[i];
    }
}