#include <bits/stdc++.h>
using namespace std;


int longestAlt(const string &s, char start)
{
    int cnt = 0;
    char expect = start;
    for (char c : s)
    {
        if (c == expect)
        {
            cnt++;
            expect = (expect == '0' ? '1' : '0');
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int n0 = 0, n1 = 0;
        for (char c : s)
            (c == '0' ? n0 : n1)++;
        int d = n0 - n1;

        int L0 = longestAlt(s, '0');
        int L1 = longestAlt(s, '1');

        int best = -1;
      
        if (abs(d) <= 1)
        {
            if (L0 % 2 == 0)
                best = max(best, L0);
            else if (L0 > 1)
                best = max(best, L0 - 1);
            if (L1 % 2 == 0)
                best = max(best, L1);
            else if (L1 > 1)
                best = max(best, L1 - 1);
        }

        if (d >= 0 && d <= 2)
        {
            if (L0 % 2 == 1)
                best = max(best, L0);
            else if (L0 > 1)
                best = max(best, L0 - 1);
        }
        if (d >= -2 && d <= 0)
        {
            if (L1 % 2 == 1)
                best = max(best, L1);
            else if (L1 > 1)
                best = max(best, L1 - 1);
        }

        cout << (best == -1 ? -1 : n - best) << '\n';
    }
    return 0;
}