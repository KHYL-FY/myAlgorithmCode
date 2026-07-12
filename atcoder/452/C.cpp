#include <iostream>
#include <vector>
using namespace std;

bool u[10 + 5][27];
string str[200005];

// vector<string> str[10 + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int bones[10 + 5][2];
    for (int i = 1; i <= n; i++)
    {
        cin >> bones[i][1] >> bones[i][2];
    }

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> str[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[j].length() != bones[i][1])
                continue;
            char l = str[j][bones[i][2] - 1];
            u[i][(int)l - 'a' + 1] = true;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= 26; j++)
    //     {
    //         cout << u[i][j];
    //     }
    //     cout << endl;
    // }
    bool flag;
    for (int i = 1; i <= m; i++)
    {
        if (str[i].length() != n)
        {
            cout << "No" << endl;
            continue;
        }

        flag = true;
        for (int j = 1; j <= n; j++)
        {
            char l = str[i][j - 1];
            // cout << l << endl;
            if (!u[j][l - 'a' + 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}