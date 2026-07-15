#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2010;

int c[N][N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
};
int n, sum;
bool findans = false;
void dfs(bool use[], int nowSum, vector<int> num)
{
    // cout << nowSum << endl;
    // if (num.size() == 4)
        if (nowSum > sum || findans)
            return;
    if (nowSum == sum)
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
            flag = flag && use[i];
        if (flag)
        {
            findans = true;
            for (int i = 0; i < num.size(); i++)
                cout << num[i] << " ";
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (findans)
            return;
        if (use[i] == true)
            continue;

        num.push_back(i);
        use[i] = true;
        dfs(use, nowSum + c[n - 1][num.size() - 1] * i, num);
        if (findans)
            return;
        use[i] = false;
        num.pop_back();
    }

    return;
}
int main()
{
    init();

    cin >> n >> sum;
    // for (int i = 0; i <= 4; i++)
    //     cout << c[4][i] << " ";
    // cout << endl;
    bool use[13];
    vector<int> a;
    dfs(use, 0, a);

    return 0;
}