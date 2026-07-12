#include <iostream>

using namespace std;

int main()
{
    int l, q, c;
    cin >> l >> q >> c;
    if (!c)
    {
        if (l != 0 && q != 0)
            cout << "-1";
        else
        {
            for (int i = 1; i <= l; i++)
                cout << "L";
            for (int i = 1; i <= q; i++)
                cout << "Q";
        }
        return 0;
    }
    int lk = c / 2 + 1;
    int qk = (c + 1) / 2;

    if (l >= lk && q >= qk)
    {
        // L 开头
        for (int i = 1; i <= l - lk; i++)
            cout << "L";
        for (int i = 1; i <= lk + qk - 1; i++)
        {
            if (i & 1)
                cout << "L";
            else
                cout << "Q";
        }
        if ((lk + qk) & 1)
        {
            for (int i = 1; i <= q - qk; i++)
                cout << "Q";
            cout << "L";
        }
        else
        {
            cout << "Q";
            for (int i = 1; i <= q - qk; i++)
                cout << "Q";
        }
    }
    else
    {
        swap(lk, qk);
        if (l < lk || q < qk)
        {
            cout << "-1";
            return 0;
        }
        // Q 开头
        for (int i = 1; i <= lk + qk; i++)
        {
            if (i & 1)
                cout << "Q";
            else
                cout << "L";
        }
        for (int i = 1; i <= q - qk; i++)
            cout << "Q";
    }
}