#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct tree
{
    int id;
    vector<pair<char, int>> child;
};

tree version[100005];
int dfs_[100005]; 
int idx = 0;

void dfs(int u)
{
    idx++;
    dfs_[idx] = version[u].id;

    sort(version[u].child.begin(), version[u].child.end());

    for (int i = 0; i < version[u].child.size(); i++)
    {
        char c = version[u].child[i].first; 
        int v = version[u].child[i].second;
        dfs(v);
    }
}

int main()
{
    int t;
    cin >> t;

    int n;
    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            version[i].child.clear();
            version[i].id = i;
        }

        for (int i = 2; i <= n; i++)
        {
            int pre;
            char a;
            cin >> pre >> a;
            version[pre].child.push_back({a, i});
        }

        idx = 0;
        dfs(1);
        for (int i = 1; i <= n; i++)
        {
            cout << dfs_[i] << " ";
        }
        cout << endl;
    }

    return 0;
}