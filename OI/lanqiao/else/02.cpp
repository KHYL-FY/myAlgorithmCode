#include <iostream>

using namespace std;

bool a[14];
int num[4];
int ans = 0;
void digui(int n)
{
    if (n == 3)
    {
        if (num[0] + num[1] != num[2])
            return;
    }
    if (n == 6)
    {
        if (num[0] - num[1] != num[2])
            return;
    }
    if (n == 9)
    {
        if (num[0] * num[1] != num[2])
            return;
    }
    if (n == 12)
    {
        if (num[0] / num[1] != num[2])
            return;
        else
        {
            if (num[0] % num[1] == 0)
            {
                ans++;
            }
            return;
        }
    }
    for (int i = 1; i <= 13; i++)
    {
        if (a[i] == false)
        {
            a[i] = true;
            num[n % 3] = i;
            digui(n + 1);
            a[i] = false;
        }
    }
}
int main()
{
    for (int i = 1; i <= 13; i++)
    {
        a[i] = false;
    }
    digui(0);
    cout << ans;
}