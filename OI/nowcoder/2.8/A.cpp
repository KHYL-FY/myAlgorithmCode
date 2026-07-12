#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    bool out = false;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= '1' && a[i] <= '9')
            out = true;
        if (!out)
            continue;

        cout << a[i];
    }
}