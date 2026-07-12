#include <iostream>
#include <map>
using namespace std;
map<int, int> clothes;
int main()
{
    int n, m;

    cin >> n >> m;
    int f;
    for (int i = 1; i <= n; i++)
    {
        cin >> f;
        clothes[f]++;
    }
    bool ans1 = true, ans2 = true;

    for (int i = 1; i <= m; i++)
    {
        if (clothes[i] == 0)
            ans2 = false;
        if (clothes[i] > 1)
            ans1 = false;
    }
    if (ans1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (ans2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}