#include <iostream>

using namespace std;
int n;
int t[15], d[15], l[15];
bool use[15];
bool ans = false;
void dfs(int time, int i)
{
    // if (time > t[i] + d[i])
    //     return;
    if (i == n)
    {
        ans = true;
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (!use[j])
        {
            if (time > t[j] + d[j])
                return;
            use[j] = true;
            dfs(max(t[j], time) + l[j], i + 1);
            use[j] = false;
        }
        if (ans)
            return;
    }
}
int main()
{
    int T;

    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = false;
        for (int i = 1; i <= n; i++)
        {
            cin >> t[i] >> d[i] >> l[i];
            use[i] = false;
        }
        dfs(0, 0);
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}