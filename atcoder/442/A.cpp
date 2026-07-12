#include <iostream>

using namespace std;
int main()
{
    int ans = 0;
    string a;
    cin >> a;
    int len = a.length();

    for (int i = 0; i < len; i++)
    {
        if (a[i] == 'i' || a[i] == 'j'){
            ans++;
        }
    }

    cout << ans;
}