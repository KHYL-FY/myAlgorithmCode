#include <iostream>

using namespace std;
#define ll unsigned long long

ll s[1001][1001];
ll sum[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int n, m, q;

    while (t--)
    {
        //scanf("%d%d%d", &n, &m, &q);

        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> s[i][j];
                //scanf("%llu", &s[i][j]);

        sum[0][0] = sum[0][1] = sum[1][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                sum[i][j] = s[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        int u, v, x, y;
        ll q_ans = 0;

        for (int i = 1; i <= q; i++)
        {
            cin >> u >> v >> x >> y;
            //scanf("%d%d%d%d", &u, &v, &x, &y);
            q_ans ^= sum[x][y] - sum[u - 1][y] - sum[x][v - 1] + sum[u - 1][v - 1];

            // q_ans ^= q_ans;
        }

        cout << q_ans << endl;
    }
}