#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int **square = new int *[n + 1];
    for (int i = 0; i <= n; ++i)
        square[i] = new int[n + 1]{0};

    square[1][(n + 1) / 2] = 1;

    struct locate
    {
        int hang;
        int lie;
    };

    locate last{1, (n + 1) / 2};

    for (int i = 2; i <= n * n; i++)
    {
        if (last.hang == 1 && last.lie != n)
        {
            square[n][last.lie + 1] = i;
            last.hang = n;
            last.lie++;
            continue;
        }
        if (last.lie == n && last.hang != 1)
        {
            square[last.hang - 1][1] = i;
            last.hang--;
            last.lie = 1;
            continue;
        }
        if (last.hang == 1 && last.lie == n)
        {
            square[last.hang + 1][last.lie] = i;
            last.hang++;
            continue;
        }
        if (last.hang != 1 && last.lie != n)
        {
            if (square[last.hang - 1][last.lie + 1] == 0)
            {
                square[last.hang - 1][last.lie + 1] = i;
                last.hang--;
                last.lie++;
                continue;
            }
            else
            {
                square[last.hang + 1][last.lie] = i;
                last.hang++;
                continue;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    delete[] square;

    return 0;
}