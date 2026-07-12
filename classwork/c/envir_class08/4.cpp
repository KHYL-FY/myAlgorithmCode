#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;

    int right = a.length() - 1;

    int left = 0;

    while (right >= left)
    {
        if (a[right] != a[left])
        {
            cout << "不是回文字符串";
            return 0;
        }
        left++;
        right--;
    }

    cout << "是回文字符串";
}