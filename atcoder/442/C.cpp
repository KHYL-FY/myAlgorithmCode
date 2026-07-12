#include <iostream>

using namespace std;

#define ll long long

int deg[200005];
int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    ll ava, ans;
    for (int i = 1; i <= n; i++)
    {
        ava = n - 1 - deg[i];
        if (ava >= 3)
        {
            ans = ava * (ava - 1) * (ava - 2) / 6;
            cout << ans << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    return 0;
}