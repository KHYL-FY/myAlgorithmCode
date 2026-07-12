#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ll yingliang = 0;
    ll n, caozuo;
    bool bofang = false;

    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        cin >> caozuo;

        switch (caozuo)
        {
        case 1:
            yingliang++;
            break;
        case 2:
            if (yingliang >= 1)
            {
                yingliang--;
            }
            break;
        case 3:
            if (bofang)
                bofang = false;
            else
                bofang = true;
            break;
        }

        if (bofang && yingliang >= 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}