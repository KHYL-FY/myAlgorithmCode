#include <iostream>
#include <cmath>
using namespace std;

int n, k, a[100];

void cout_a()
{
    for (int i = 1; i <= k; i++)
    {
        cout << a[i]<<" ";
    }
    return;
}

void team(bool use[], int p)
{
    for (int i = 1; i <= n; i++)
    {
        if (p > k)
        {
            cout_a();
            cout << endl;
            return;
        }
        if (use[i] == 0)
        {
            a[p] = i;
            use[i] = 1;
            team(use, p + 1);
            use[i] = 0;
        }
    }
    return;
}
int main()
{
    bool use[50] = {0};
    cin >> n >> k;

    team(use, 1);
}