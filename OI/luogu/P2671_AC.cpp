/*
O(n)

将给定的式子(x+z)*(numx*numz)拆开
x*numx + x*numz + z*numx + z*numz

x < z 且同奇偶,固定z,对于每个x < z,我们都要进行上面那个式子计算
直接算是O(n^2).
我们利用前缀和, 维护上面拆开的四个前缀和,xnumx,x,numx,znumz的个数, 固定z, 对于每个z, 可以直接以O(1)计算出来
就不用再从头遍历一遍,这样对于每个z的计算从O(n)降到O(1).整个计算复杂度是O(n)

*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 10007;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> num(n + 1);
    vector<ll> color(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= n; i++)
        cin >> color[i];

    ll ans = 0;
    vector<vector<ll>> xnumx(m + 1, vector<ll>(2));
    vector<vector<ll>> x(m + 1, vector<ll>(2));
    vector<vector<ll>> numx(m + 1, vector<ll>(2));
    vector<vector<ll>> z(m + 1, vector<ll>(2));

    // vector<vector<ll>> znumz(m + 1, vector<ll>(2));

    for (int i = 1; i <= n; i++)
    {
        bool odd = i % 2;

        // xnumx xnumz znumx znumz
        ans = (ans + xnumx[color[i]][odd]) % mod;
        ans = (ans + (x[color[i]][odd] * num[i]) % mod) % mod;
        ans = (ans + (numx[color[i]][odd] * i) % mod) % mod;
        ans = (ans + (i * num[i] * z[color[i]][odd]) % mod) % mod;

        // cout << xnumx[color[i]][odd] << " " << x[color[i]][odd] << " " << numx[color[i]][odd] << " " << ans << endl;
        // 5 2 25 10
        xnumx[color[i]][odd] = (xnumx[color[i]][odd] + (i * num[i]) % mod) % mod;
        x[color[i]][odd] = (x[color[i]][odd] + i) % mod;
        numx[color[i]][odd] = (numx[color[i]][odd] + num[i]) % mod;
        z[color[i]][odd]++;
    }

    cout << ans;
}