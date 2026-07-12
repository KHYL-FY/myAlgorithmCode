#include <iostream>
#define N 1000005

using namespace std;

string river[3];

int main()
{
    cin >> river[1] >> river[2];
    int maxlen = river[1].length();

    int p = 0;
    while (river[1][p] != '#' && river[2][p] != '#')
        p++;
    // cout << p << endl;
    bool checkmachine_up = false, checkmachine_down = false;
    if (river[1][p] == '#')
        checkmachine_up = true;
    if (river[2][p] == '#')
        checkmachine_down = true;
    // cout << checkmachine_up << checkmachine_down;
    bool nextc_up = false, nextc_down = false;

    int ans = 0;
    int nextp;

    while (p < maxlen )
    {
        nextc_up = false;
        nextc_down = false;

        nextp = p + 1;
        
        // while ((river[1][nextp] == '#' && river[1][nextp - 1] == '#') || (river[2][nextp] == '#' && river[2][nextp - 1] == '#') || (river[1][nextp] == '.' && river[2][nextp] == '.'))
        //     nextp++;
        // cout << nextp << endl;

        if (river[1][nextp] == '#')
            nextc_up = true;
        if (river[2][nextp] == '#')
            nextc_down = true;

        if (checkmachine_up && nextc_up)
            ans += (nextp - p - 1);
        else if (checkmachine_down && nextc_down)
            ans += (nextp - p - 1);
        else
        {
            ans += (nextp - p);
            if (!nextc_up)
                river[1][nextp] = '#';
            if (!nextc_down)
                river[2][nextp] = '#';
        }
        // cout << ans<<endl;
        if (river[1][nextp] == '#')
            checkmachine_up = true;
        else
            checkmachine_up = false;
        if (river[2][nextp] == '#')
            checkmachine_down = true;
        else
            checkmachine_down = false;
        p = nextp;
    }
    cout << river[1] << endl
         << river[2];
    cout << ans;
}