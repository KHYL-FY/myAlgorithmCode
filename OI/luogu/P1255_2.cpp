#include <iostream>
using namespace std;
int stairs[5002][5002] = {0};
int main()
{
    int n;
    cin >> n;
    
    stairs[1][1] = 1;
    stairs[2][1] = 2;

    int len = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            stairs[i][j] = stairs[i - 1][j] + stairs[i - 2][j];
        }
        for (int j = 1; j <= len; j++)
        {
            if (stairs[i][j] >= 10)
            {
                stairs[i][j + 1] = stairs[i][j + 1] + stairs[i][j] / 10;
                stairs[i][j] = stairs[i][j] % 10;
                if (stairs[i][len + 1] != 0)
                {
                    len++;
                }
            }
        }
    }

    for (int i = len; i > 0; i--)
    {
        cout << stairs[n][i];
    }
}