#include <iostream>

using namespace std;

void trace(int n, int m, int a, int b)
{
    if (a <= 0 || b <= 0 || n <= 0 || m <= 0)
        return;

    if (a > 2)
    {
        for (int i = 1; i <= m - 1; i++)
            cout << "R";
        cout << "D";
        for (int i = 1; i <= m - 1; i++)
            cout << "L";
        cout << "D";

        trace(n - 2, m, a - 2, b);
    }
    else if (a <= n - 2)
    {
        trace(n - 2, m, a, b);
        cout << "D";
        for (int i = 1; i <= m - 1; i++)
            cout << "L";
        cout << "D";
        for (int i = 1; i <= m - 1; i++)
            cout << "R";
    }
    else if (b > 2)
    {
        for (int i = 1; i <= n - 1; i++)
            cout << "D";
        cout << "R";
        for (int i = 1; i <= n - 1; i++)
            cout << "U";
        cout << "R";

        trace(n, m - 2, a, b - 2);
    }
    else if (b <= m - 2)
    {
        trace(n, m - 2, a, b);

        cout << "R";
        for (int i = 1; i <= n - 1; i++)
            cout << "U";
        cout << "R";
        for (int i = 1; i <= n - 1; i++)
            cout << "D";
    }

    else if (a > 0 && a <= n && b > 0 && b <= m)
    {
        if (a == 1 && b == 2)
            cout << "DR";
        if (a == 2 && b == 1)
            cout << "RD";
        return;
    }

    return;
}
void solve()
{
    int n, a, b;

    cin >> n >> a >> b;

    if (n % 2 == 1)
    {
        cout << "No" << endl;
        return;
    }
    if ((a + b) % 2 == 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    trace(n, n, a, b);
    cout << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}