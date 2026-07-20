#include <iostream>

using namespace std;

void solve()
{
    int n;
    int add2cnt = 0, sub2cnt = 0;
    cin >> n;

    int num1, num2;
    int sum = 0;
    cin >> num1;
    sum += num1;
    for (int i = 1; i < n; i++)
    {
        cin >> num2;
        sum += num2;
        if (i % 2 == 1)
        {
            if (num1 + num2 == 2)
                add2cnt++;
            else if (num1 + num2 == -2)
                sub2cnt++;
        }

        num1 = num2;
    }
    if (n % 2 != 0 || sum % 2 != 0 || (add2cnt + sub2cnt) % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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