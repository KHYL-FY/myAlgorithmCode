
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct qnode
{
    int id;
    ll w;

    qnode(ll _w, int _id) : w(_w), id(_id) {}

    bool operator<(const qnode a) const
    {
        return w > a.w;
    }
};

int treeID(int x, int n) { return x - n; }

void dfs(int nowid, string &cur, const int &n, const vector<pair<int, int>> &htree, vector<string> &hcode)
{
    if (nowid <= n)
    {
        hcode[nowid] = cur;
        return;
    }

    cur += '0';
    dfs(htree[treeID(nowid, n)].first, cur, n, htree, hcode);
    cur.pop_back();

    cur += '1';
    dfs(htree[treeID(nowid, n)].second, cur, n, htree, hcode);
    cur.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int M = n * 2 + 5;

    priority_queue<qnode> q;
    vector<string> str(n + 1);
    vector<pair<int, int>> htree(M);
    vector<string> hcode(n + 1);

    ll w;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i] >> w;
        q.push(qnode(w, i));
    }

    if (n == 1)
    {
        cout << str[1] << " " << "0";
        return 0;
    }

    int nid = n;
    while (q.size() > 1)
    {
        qnode a = q.top();
        q.pop();
        qnode b = q.top();
        q.pop();

        nid++;
        q.push(qnode(a.w + b.w, nid));
        htree[treeID(nid, n)] = {a.id, b.id};
    }

    string cur = "";
    dfs(nid, cur, n, htree, hcode);

    for (int i = 1; i <= n; i++)
    {
        cout << str[i] << " " << hcode[i] << endl;
    }
}