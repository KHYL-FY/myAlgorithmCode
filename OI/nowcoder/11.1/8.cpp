#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[105][3];

    int n, k, m;
    cin >> n >> k >> m;

    int people = n;
    int pointer = k;

    for (int i = 1; i < n; i++)
    {
        a[i][1] = i + 1;
        a[i][2] = i - 1;
    }
    a[0][1] = 1;
    a[0][2] = n - 1;
    a[n - 1][1] = 0;
    a[n - 1][2] = n - 2;

    while (people != 1)
    {
        for (int i = 1; i < m; i++)
        {
            pointer = a[pointer][1];
        }

        a[a[pointer][2]][1] = a[pointer][1];
        a[a[pointer][1]][2] = a[pointer][2];
       
        pointer = a[pointer][1];
        people--;
    }

    cout << pointer;
}