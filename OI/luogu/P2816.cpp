#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    map<int, int> count;
    vector<int> x;
    int a;
    // int maxc = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> a;
    //     count[a]++;
    //     maxc = max(maxc, count[a]);
    // }

    // cout << maxc ;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> a;
    //     if (count[a] == 0)
    //     {
    //         count[a]++;
    //         x.push_back(a);
    //         sort(x.begin(), x.end(), cmp);
    //     }
    //     else
    //         count[a]++;
    // }

    

    cout << ans;
}