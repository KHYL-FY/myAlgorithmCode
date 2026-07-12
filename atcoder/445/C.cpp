#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
vector<int> ans;
int dfs(int p)
{
    if (ans[p] != 0)
        return ans[p];
    if (num[p] == p)
        return ans[p] = p;
    return ans[p] = dfs(num[p]);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= n; i++)
        ans[i] = 0;
    int p;
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        cout << ans[i] << " ";
    }
    return 0;
}