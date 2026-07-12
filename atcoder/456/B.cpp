#include <iostream>

using namespace std;

struct dice
{
    int _4 = 0, _5 = 0, _6 = 0;
};

void cin_(dice &a)
{
    int num;
    for (int i = 1; i <= 6; i++)
    {
        cin >> num;
        switch (num)
        {
        case 4:
            a._4++;
            break;
        case 5:
            a._5++;
            break;
        case 6:
            a._6++;
            break;
        }
    }

    return;
}
int main()
{
    dice a, b, c;
    cin_(a);
    cin_(b);
    cin_(c);

    int p = 0;
    p += a._4 * b._5 * c._6;
    p += a._4 * b._6 * c._5;

    p += a._5 * b._4 * c._6;
    p += a._5 * b._6 * c._4;

    p += a._6 * b._5 * c._4;
    p += a._6 * b._4 * c._5;

    double ans = (double)p / 216.0;
    cout << ans;
}