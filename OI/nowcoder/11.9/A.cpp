#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1005];
    int i = 1;
    while ((a[i] = getchar()) != EOF)
    {
        i++;
    }
    i -= 4;
    for (int j = 1; j <= i; j++)
    {
        putchar(a[j]);
    }
}