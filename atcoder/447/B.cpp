#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int count[27];
    int len = a.length();
    int maxCount = 0;
    for (int i = 0; i < 27; i++)
        count[a[i] - 'a'] = 0;

    for (int i = 0; i < len; i++)
    {
        count[a[i] - 'a']++;
        maxCount = max(count[a[i] - 'a'], maxCount);
    }
    for (int i = 0; i < len; i++)
    {
        if (count[a[i] - 'a'] == maxCount)
            continue;
        cout << a[i];
    }
    return 0;
}