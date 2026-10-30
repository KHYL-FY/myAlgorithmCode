#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> coin(n, vector<bool>(m));
    for (auto &i : coin)
        for (auto &j : i)
            cin >> j;
}