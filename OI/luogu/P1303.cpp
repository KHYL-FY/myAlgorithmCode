#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int ans[100001] = {0};
int main()
{
    string a, b;
    cin >> a >> b;
    int alen = a.length();
    int blen = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < alen; i++)
        for (int j = 0; j < blen; j++)
            ans[i + j] += (a[i] - '0') * (b[j] - '0');
    int anslen = alen + blen;
    for (int i = 0; i < anslen; i++)
        if (ans[i] >= 10)
        {
            ans[i + 1] += (ans[i] / 10);
            ans[i] = ans[i] % 10;
        }
    while (ans[anslen] == 0 && anslen > 0)
        anslen--;
    for (int i = anslen; i >= 0; i--)
        cout << ans[i];
}