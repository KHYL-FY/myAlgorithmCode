#include <iostream>
#include <cmath>
#include <map>
using namespace std;

bool prim(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int n, k, ans = 0;
int a[30];
map<int, bool> use;
void dfs(int sum, int p, int i)
{
    if (i > n + 1)
        return;
    if (p == k)
    {
        // cout << sum << endl;
        if (prim(sum) || use[sum] == true)
        {
            ans++;
            use[sum] = true;
            // cout << sum << endl;
        }

        return;
    }
    // cout << p << " " << i << endl;
    dfs(sum + a[i], p + 1, i + 1);
    dfs(sum, p, i + 1);
}
int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, 1);

    cout << ans;
}