#include <iostream>
#define ll long long
using namespace std;
ll s[200005];
ll a[200005];
#define M 200001
#define ds
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    for (int i = 0; i <= M; i++)
        a[i] = s[i] = 0;

    int n, k, q;
    cin >> n >> k >> q;
    int l, r, min_ = M + 1, max_ = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
        max_ = max(max_, r);
        min_ = min(min_, l);
    }
    a[max_ + 1] = 0;
    a[min_ - 1] = 0;

    for (int i = min_; i <= max_; i++)
    {
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= M; i++)
    {
        if (a[i] >= k)
            a[i] = 1;
        else
            a[i] = 0;
        s[i] = s[i - 1] + a[i];
    }
#ifdef d
    for (int i = 90; i <= 100; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
#endif
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;

        cout << s[r] - s[l - 1] << endl;
    }
}