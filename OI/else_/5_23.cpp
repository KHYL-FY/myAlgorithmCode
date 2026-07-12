#include <iostream>

using namespace std;

int main()
{
    int l = 1, r = 101, mid;

    int a;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        cout << "? " << mid << endl;
        cin >> a;
        if (a)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << "! " << l;
}