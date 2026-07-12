#include <iostream>

using namespace std;

int main()
{
    int square[102][103] = {0};
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> square[i][j];
            square[i][j] += square[i - 1][j] + square[i][j - 1] - square[i - 1][j - 1];
        }
    }

    int maxSize = min(m, n), ansSize = 0;

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            for (int sizee = 1; sizee <= maxSize; sizee++)
            {
                if (i - sizee <= 0 || j - sizee <= 0)
                    break;
                if (square[i][j] - square[i][j - sizee] - square[i - sizee][j] + square[i - sizee][j - sizee] == sizee * sizee)
                {
                    ansSize = max(ansSize, sizee);
                }
            }
        }
    }
    cout << ansSize;
}
