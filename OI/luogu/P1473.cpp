#include <iostream>
#include <stack>

using namespace std;

int n;
char a[11];
int sum = 0, num = 0;
void dfs(int p)
{
    if (p == n + 1)
    {
        sum = 0;
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == ' ')
                continue;

            num = i;
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] != ' ')
                    break;
                num = num * 10 + j;
            }

            if (a[i] == '+')
                sum += num;
            if (a[i] == '-')
                sum -= num;
        }
        if (sum == 0)
        {
            cout << 1;
            for (int i = 2; i <= n; i++)
                cout << a[i] << i;
            cout << endl;
        }
        return;
    }
    a[p] = ' ';
    dfs(p + 1);
    a[p] = '+';
    dfs(p + 1);
    a[p] = '-';
    dfs(p + 1);
}
int main()
{
    cin >> n;
    a[1] = '+';
    dfs(2);
}