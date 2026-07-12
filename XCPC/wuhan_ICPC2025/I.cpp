#include <iostream>

using namespace std;

int a[55][55];
bool use[2505];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k - n < 0 || n * n - n + 2 <= k)
        {
            cout << "No" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = 0;
        for (int i = 1; i <= n * n; i++)
            use[i] = false;

        cout << "Yes" << endl;
        a[1][1] = k;
        use[k] = true;

        for (int i = 2; i <= n; i++)
        {
            a[1][i] = i - 1;
            a[i][i] = n * n - i + 2;
            use[n * n - i + 2] = use[i - 1] = true;
        }




        int num = 1;
        while (use[num])
            num++;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 0)
                {   
                    while (use[num])
                        num++;
                    use[num] = true;
                    a[i][j] = num;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
}