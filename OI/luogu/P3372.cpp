#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class segTree
{

private:
    const static ll MAX = 1e5 + 5;
    ll tree[MAX];
    ll data[MAX];
    ll ql, qr;
    ll data_length = 0, tree_length = 0;
    ll sum;

    void build(ll rt, ll left, ll right)
    {
        if (left == right)
        {
            tree[rt] = data[left];
            return;
        }

        ll mid = left + (right - left) / 2;
        build(2 * rt, left, mid);
        build(2 * rt + 1, mid + 1, right);
        tree[rt] = tree[2 * rt + 1] + tree[2 * rt];

        return;
    }
    ll getsum(ll rt, ll left, ll right)
    {
        if (ql <= left && qr >= right)
        {
            return tree[rt];
        }

        ll mid = left + (right - left) / 2;
        if (ql > left)
            sum += getsum(2 * rt, left, mid);
        if (qr < right)
            sum += getsum(2 * rt + 1, mid + 1, right);
    }

public:
    void cin_data(const ll num)
    {
        data[++data_length] = num;
    }
    void bulid_tree(const ll n)
    {
        build(1, 1, data_length);
    }
    ll qsum(ll l, ll r)
    {
        ql = l;
        qr = r;
        sum = 0;
        return getsum(1, 1, 5);
    }
};

int main()
{
    ll n;
    segTree tree;

    cin >> n;

    ll num;
    for (ll i = 1; i <= n; i++)
    {
        cin >> num;
        tree.cin_data(num);
    }
    tree.bulid_tree(n);

    // for (int i = 1; i <= 5; i++)
    //     cout << tree.data[i]<<" ";
    // ll sum = tree.qsum(1, 5);
    // cout << sum;
    // for (ll i = 1; i <= n; i++)
    //     cin >> data[i];

    // build(data, tree, 1, 1, n);
    // for (ll i = 1; i <= 2 * n; i++)
    //     cout << tree[i] << " ";
}