#include <iostream>

using namespace std;
#define ll long long
#define M 0x7fffffffff
ll d[21][21][21];

ll dfs(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
    {
        d[20][20][20] = dfs(20, 20, 20);
        return d[20][20][20];
    }

    if (a < b && b < c)
    {
        ll num1, num2, num3;
        if (d[a][b][c - 1] != M)
            num1 = d[a][b][c - 1];
        else
        {
            num1 = dfs(a, b, c - 1);
            d[a][b][c - 1] = num1;
        }
        if (d[a][b - 1][c - 1] != M)
            num2 = d[a][b - 1][c - 1];
        else
        {
            num2 = dfs(a, b - 1, c - 1);
            d[a][b - 1][c - 1] = num2;
        }
        if (d[a][b - 1][c] != M)
            num3 = d[a][b - 1][c];
        else
        {
            num3 = dfs(a, b - 1, c);
            d[a][b - 1][c] = num3;
        }
        d[a][b][c] = num1 + num2 - num3;
        return num1 + num2 - num3;
    }
    else
    {
        ll num1, num2, num3, num4;
        if (d[a - 1][b][c] != M)
            num1 = d[a - 1][b][c];
        else
        {
            num1 = dfs(a - 1, b, c);
            d[a - 1][b][c] = num1;
        }

        if (d[a - 1][b - 1][c] != M)
            num2 = d[a - 1][b - 1][c];
        else
        {
            num2 = dfs(a - 1, b - 1, c);
            d[a - 1][b - 1][c] = num2;
        }

        if (d[a - 1][b][c - 1] != M)
            num3 = d[a - 1][b][c - 1];
        else
        {
            num3 = dfs(a - 1, b, c - 1);
            d[a - 1][b][c - 1] = num3;
        }

        if (d[a - 1][b - 1][c - 1] != M)
            num4 = d[a - 1][b - 1][c - 1];
        else
        {
            num4 = dfs(a - 1, b - 1, c - 1);
            d[a - 1][b - 1][c - 1] = num4;
        }
        d[a][b][c] = num1 + num2 + num3 - num4;
        return num1 + num2 + num3 - num4;
    }
}
int main()
{
    ll a = 0, b = 0, c = 0;

    for (ll i = 0; i <= 20; i++)
        for (ll j = 0; j <= 20; j++)
            for (ll q = 0; q <= 20; q++)
                d[i][j][q] = M;

    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            return 0;
        }

        printf("w(%lld, %lld, %lld) = ", a, b, c);
        cout << dfs(a, b, c) << endl;
    }
}