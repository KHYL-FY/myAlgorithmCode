#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int len = a.length();
    if (a[0] == a[len - 1])
        cout << "Yes";
    else
        cout << "No";

    return 0;
}