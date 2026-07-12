#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    string a;
    while (t--)
    {
        cin >> n;
        cin >> a;
        switch (n)
        {
        case 1:
            cout << 0 << endl;
            break;
        case 3:
            if (a != "ABABAB" && a != "BABABA")
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
            break;
        case 2:
            if (a != "ABAB" && a != "BABA")
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
            break;
        }
    }
}