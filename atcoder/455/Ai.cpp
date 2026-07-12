#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 300005;

int up[MAXN];
int down[MAXN];
int pile_top[MAXN];
int pile_bottom[MAXN];
int belong[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        pile_top[i] = i;
        pile_bottom[i] = i;
        belong[i] = i;
        up[i] = 0;
        down[i] = 0;
    }

    while (Q--)
    {
        int C, P;
        cin >> C >> P;

        int pile_C = belong[C];
        int pile_P = belong[P];

        int old_bottom_C = pile_bottom[pile_C];
        int cur = C;
        while (cur != 0)
        {
            belong[cur] = pile_P;
            cur = up[cur];
        }

        int top_C = pile_top[pile_C];
        int bottom_C = pile_bottom[pile_C];

        if (down[C] != 0)
        {
            up[down[C]] = 0;
            pile_top[pile_C] = top_C;
        }
        else
        {
            pile_top[pile_C] = 0;
        }
        pile_bottom[pile_C] = down[C];

        int old_top_P = pile_top[pile_P];
        pile_top[pile_P] = top_C;

        down[C] = P;

        if (old_top_P != 0)
        {
            int bottom_of_C = C;
            while (up[bottom_of_C] != 0)
            {
                bottom_of_C = up[bottom_of_C];
            }
            up[bottom_of_C] = old_top_P;
            down[old_top_P] = bottom_of_C;
        }

        up[P] = C;
    }

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        int cur = pile_bottom[i];
        while (cur != 0)
        {
            cnt++;
            cur = up[cur];
        }
        cout << cnt << '\n';
    }

    return 0;
}
