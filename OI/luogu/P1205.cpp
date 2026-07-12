#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char square_begin[n + 1][n + 1];
    char square_end[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> square_begin[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> square_end[i][j];

    // 1
    bool ans1 = true;
    for (int i = 1, u = 1; i <= n; i++, u++)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                ans1 = false;
                break;
            }
        }
        if (ans1 == false)
            break;
    }
    if (ans1 == true)
    {
        cout << "1";
        return 0;
    }

    // 2
    bool ans2 = true;
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[u][v])
            {
                ans2 = false;
                break;
            }
        }
        if (ans2 == false)
            break;
    }
    if (ans2 == true)
    {
        cout << "2";
        return 0;
    }

    // 3
    bool ans3 = true;
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = 1; j <= n; j++, v++)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                ans3 = false;
                break;
            }
        }
        if (ans3 == false)
            break;
    }
    if (ans3 == true)
    {
        cout << "3";
        return 0;
    }
    // 4
    bool ans4 = true;
    for (int i = 1, u = 1; i <= n; i++, u++)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[u][v])
            {
                ans4 = false;
                break;
            }
        }
        if (ans4 == false)
            break;
    }
    if (ans4 == true)
    {
        cout << "4";
        return 0;
    }

    // 5
    bool ans51 = true;
    for (int i = 1, u = 1; i <= n; i++, u++)
    {
        for (int j = 1, v = 1; j <= n; j++, v++)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                ans51 = false;
                break;
            }
        }
        if (ans51 == false)
            break;
    }

    bool ans52 = true;
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = 1; j <= n; j++, v++)
        {
            if (square_end[i][j] != square_begin[u][v])
            {
                ans52 = false;
                break;
            }
        }
        if (ans52 == false)
            break;
    }

    bool ans53 = true;
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                ans53 = false;
                break;
            }
        }
        if (ans53 == false)
            break;
    }

    if (ans51 || ans52 || ans53)
    {
        cout << "5";
        return 0;
    }

    //6

    bool ans6 = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (square_end[i][j] != square_begin[i][j])
            {
                ans6 = false;
                break;
            }
        }
        if (ans6 == false)
            break;
    }
    if (ans6 == true)
    {
        cout << "6";
        return 0;
    }

    //7
    cout << "7";
    return 0;
}