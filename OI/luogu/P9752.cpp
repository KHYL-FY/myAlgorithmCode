#include <iostream>
#include <string>
using namespace std;

int main()
{
    short int mima[100003] = {0};
    int n;
    cin >> n;
    char a;
    string wrong_mima, may_mima;
    for (int i = 1; i <= n; i++)
    {

        wrong_mima = "";
        for (int j = 1; j <= 5; j++)
        {
            cin >> a;
            wrong_mima += a;
        }

        // 1位
        for (int u = 0; u <= 4; u++)
        {
            may_mima = wrong_mima;
            for (int v = 1; v <= 9; v++)
            {
                if (may_mima[u] == '9')
                    may_mima[u] = '0';
                else
                    may_mima[u]++;

                mima[stoi(may_mima)]++;
            }
        }

        // 2位
        for (int u = 0; u <= 3; u++)
        {
            may_mima = wrong_mima;
            for (int v = 1; v <= 9; v++)
            {
                if (may_mima[u] == '9')
                    may_mima[u] = '0';
                else
                    may_mima[u]++;

                if (may_mima[u + 1] == '9')
                    may_mima[u + 1] = '0';
                else
                    may_mima[u + 1]++;

                mima[stoi(may_mima)]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100000; i++)
    {
        if (mima[i] == n)
            ans++;
    }
    cout << ans;
    return 0;
}
