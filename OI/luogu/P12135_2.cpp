#include <iostream>

using namespace std;
string river[3];
bool firstsit(int &p)
{
    if (river[1][p] == '.' && river[2][p] == '#' && river[2][p + 1] == '.')
        return true;
    else
        return false;

    // .
    // #.
}
bool secondsit(int &p)
{
    if (river[1][p] == '#' && river[2][p] == '#' && river[2][p + 1] == '.' && river[1][p + 1] == '.')
        return true;
    else
        return false;
}
bool thirdsit(int &p)
{
    if (river[1][p] == '#' && river[2][p] == '.' && river[1][p + 1] == '.')
        return true;
    else
        return false;
}
int main()
{
    cin >> river[1] >> river[2];

    int p = 0;
    int len = river[1].length();
    for (int i = river[1].length() - 1; i >= 0; i--)
    {
        if (river[1][i] == '#' || river[2][i] == '#')
        {
            len = i;
            break;
        }
    }
    len++;
    int ans = 0;
    bool jump = false;
    while (p < len - 1)
    {
        jump = false;
        if (firstsit(p))
        {
            river[2][p + 1] = '#';
            ans++;
        }

        else if (secondsit(p))
        {
            for (int i = p + 1; i < len; i++)
            {
                if (river[1][i] == '#')
                {
                    ans += (i - p - 1);
                    p = i;
                    jump = true;
                    break;
                }
                if (river[2][i] == '#')
                {

                    ans += (i - p - 1);
                    jump = true;
                    p = i;
                    break;
                }
            }
        }
        else if (thirdsit(p))
        {
            river[1][p + 1] = '#';
            ans++;
        }

        if (jump)
            continue;
        else
            p++;
    }

    cout << ans;
}