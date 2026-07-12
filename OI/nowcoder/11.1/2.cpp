#include <bits/stdc++.h>

using namespace std;

int a[100005];
int main()
{
    int n;
    cin >> n;
    int money25 = 0, money50 = 0, money100 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        switch (a[i])
        {
        case 25:
            money25++;
            break;
        case 50:
            money50++;
            break;
        case 100:
            money100++;
            break;
        }
    }

    sort(a + 1, a + 1 + n);

    int money = money25 * 25;

    if (money25 == money50 && money100 == 0)
    {
        cout << "YES";
        return 0;
    }
    
    if (money25 < money50)
    {
        cout << "NO";
        return 0;
    }

    money25 -= money50;

    if (money100 < min(money25, money50))
    {
        cout << "YES";
        return 0;
    }
    int a = min(money25, money50);

    money100 -= a;

    money25 -= a;

    if (money25 / 3 > money100)
    {
        cout << "YES";
        return 0;
    }
    else
        cout << "NO";
}