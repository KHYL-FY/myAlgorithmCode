#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int fuhao;
    string t, ans;
    int num1, num2;
    while (n)
    {
        n--;
        cin >> t;
        if (t[0] == 'a' || t[0] == 'b' || t[0] == 'c')
        {
            fuhao = t[0] - 'a' + 1;
            cin >> num1 >> num2;
            if (fuhao == 1)
            {
                ans = to_string(num1) + "+" + to_string(num2) + "=" + to_string(num1 + num2);
                cout << ans << endl
                     << ans.length() << endl;
                continue;
            }
            if (fuhao == 2)
            {
                ans = to_string(num1) + "-" + to_string(num2) + "=" + to_string(num1 - num2);
                cout << ans << endl
                     << ans.length() << endl;
                continue;
            }
            if (fuhao == 3)
            {
                ans = to_string(num1) + "*" + to_string(num2) + "=" + to_string(num1 * num2);
                cout << ans << endl
                     << ans.length() << endl;
                continue;
            }
        }
        else
        {
            num1 = stoi(t);
            cin >> num2;
            if (fuhao == 1)
            {
                ans = to_string(num1) + "+" + to_string(num2) + "=" + to_string(num1 + num2);
                cout << ans << endl
                     << ans.length() << endl;
                continue;
            }
            if (fuhao == 2)
            {
                ans = to_string(num1) + "-" + to_string(num2) + "=" + to_string(num1 - num2);
                cout << ans << endl
                     << ans.length() << endl;
                continue;
            }
            if (fuhao == 3)
            {
                ans = to_string(num1) + "*" + to_string(num2) + "=" + to_string(num1 * num2);
                cout << ans << endl
                     << ans.length() << endl;
                continue;
            }
        }
    }
    return 0;
}