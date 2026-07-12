#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int money25 = 0, money50 = 0;

    int money;

    for (int i = 1; i <= n; i++)
    {
        cin >> money;
        if (money == 25)
        {
            money25++;
        }
        if (money == 50)
        {
            if (money25 > 0)
            {
                money25--;
                money50++;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
        if (money == 100)
        {
            if (money25 >= 3)
            {
                money25 -= 3;
            }
            else if (money25 >= 1&&money50>=1){
                money25--;
                money50--;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}