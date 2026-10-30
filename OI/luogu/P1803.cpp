#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct t
{
    int s, e;
};

bool cmp(t a, t b)
{
    if (a.e == b.e)
        return a.s < b.s;
    return a.e < b.e;
}
int main()
{

    int n;
    cin >> n;
    vector<t> act(n);
    for (auto &i : act)
    {
        cin >> i.s >> i.e;
    }

    sort(act.begin(), act.end(), cmp);
    // for (auto &i : act)
    // {
    //     cout << i.s << i.e << endl;
    // }
    t pre;
    pre.s = act[0].s;
    pre.e = act[0].e;
    int ans = 1;
    for (auto i = act.begin() + 1; i != act.end(); i++)
    {
        if ((*i).s >= pre.e)
        {
            ans++;
            pre.s = (*i).s;
            pre.e = (*i).e;
        }
    }

    cout << ans;
}