#include <iostream>

using namespace std;

size_t s[100002] = {0};

int main()
{
    size_t n, m;

    cin >> n ;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    cin >> m;
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
}