#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    char lingjian[25][25];
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> lingjian[i][j];

        int count[5] = {0, 0, 0, 0}, k = 0;
        int dx[5] = {1, 0, -1, 0};
        int dy[5] = {0, -1, 0, 1};

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (lingjian[i][j] == '*')
                {
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + dx[x];
                        int nj = j + dy[x];
                        if (ni >= 1 && ni <= n && nj >= 1 && nj <= n)
                            if (lingjian[ni][nj] == '*')
                            {
                                count[k]++;
                            }
                    }
                    k++;
                }
            }

        sort(count, count + 4);
        
        if (count[0] == 1 && count[1] == 1 && count[2] == 1 && count[3] == 3)
            cout << "T" << endl;
        else
            cout << "L" << endl;
    }
}
