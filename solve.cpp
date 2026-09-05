#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> t;
    Fenwick(int n_) : n(n_), t(n_ + 2, 0) {}
    void add(int i, long long v) {  // 0-based
        i += 1;
        for (; i <= n; i += i & (-i)) t[i] += v;
    }
    long long sum(int i) const {   // [0, i)
        long long s = 0;
        for (; i > 0; i -= i & (-i)) s += t[i];
        return s;
    }
    int find_kth(long long k) const {  // 0-based index of k-th element (1-based k)
        int idx = 0;
        int bitmask = 1;
        while (bitmask << 1 <= n) bitmask <<= 1;
        for (; bitmask; bitmask >>= 1) {
            int nxt = idx + bitmask;
            if (nxt <= n && t[nxt] < k) {
                idx = nxt;
                k -= t[nxt];
            }
        }
        return idx;
    }
};

// 位置连续块维护
struct PosBlock {
    int n;
    vector<char> occ;
    Fenwick pos_bit, empty_bit, cnt_bit, sum_bit;
    map<int, int> l2r, r2l;
    int total_blocks, total_occ;
    PosBlock(int n_) : n(n_), occ(n_, 0), pos_bit(n_), empty_bit(n_),
                       cnt_bit(n_ + 2), sum_bit(n_ + 2),
                       total_blocks(0), total_occ(0) {
        for (int i = 0; i < n; i++) empty_bit.add(i, 1);
    }
    void add_block(int sz, long long d) {
        if (sz <= 0) return;
        cnt_bit.add(sz - 1, d);
        sum_bit.add(sz - 1, d * sz);
    }
    pair<int, int> block_of(int p) {
        long long S = pos_bit.sum(p + 1);
        long long e_before = (p + 1) - S;
        int l, r;
        if (e_before >= 1) {
            int lm1 = empty_bit.find_kth(e_before);
            l = lm1 + 1;
        } else {
            l = 0;
        }
        long long total_empty = empty_bit.sum(n);
        if (e_before + 1 <= total_empty) {
            int rp1 = empty_bit.find_kth(e_before + 1);
            r = rp1 - 1;
        } else {
            r = n - 1;
        }
        return {l, r};
    }
    void insert(int p) {
        assert(!occ[p]);
        bool hasL = p > 0 && occ[p - 1];
        bool hasR = p < n - 1 && occ[p + 1];
        if (hasL && hasR) {
            int l1 = r2l[p - 1];
            int r2 = l2r[p + 1];
            int s1 = (p - 1) - l1 + 1;
            int s2 = r2 - (p + 1) + 1;
            add_block(s1, -1); add_block(s2, -1);
            add_block(s1 + s2 + 1, 1);
            r2l.erase(p - 1);
            l2r.erase(p + 1);
            l2r[l1] = r2;
            r2l[r2] = l1;
            total_blocks--;
        } else if (hasL) {
            int l1 = r2l[p - 1];
            int s = (p - 1) - l1 + 1;
            add_block(s, -1); add_block(s + 1, 1);
            r2l.erase(p - 1);
            l2r[l1] = p;
            r2l[p] = l1;
        } else if (hasR) {
            int r2 = l2r[p + 1];
            int s = r2 - (p + 1) + 1;
            add_block(s, -1); add_block(s + 1, 1);
            l2r.erase(p + 1);
            l2r[p] = r2;
            r2l[r2] = p;
        } else {
            add_block(1, 1);
            l2r[p] = p;
            r2l[p] = p;
            total_blocks++;
        }
        occ[p] = 1;
        pos_bit.add(p, 1);
        empty_bit.add(p, -1);
        total_occ++;
    }
    void remove(int p) {
        assert(occ[p]);
        if (l2r.count(p) && r2l.count(p)) {
            occ[p] = 0;
            pos_bit.add(p, -1);
            empty_bit.add(p, 1);
            total_occ--;
            add_block(1, -1);
            l2r.erase(p); r2l.erase(p);
            total_blocks--;
        } else if (l2r.count(p)) {
            int r = l2r[p];
            int s = r - p + 1;
            occ[p] = 0;
            pos_bit.add(p, -1);
            empty_bit.add(p, 1);
            total_occ--;
            add_block(s, -1);
            add_block(s - 1, 1);
            l2r.erase(p);
            l2r[p + 1] = r;
            r2l[r] = p + 1;
        } else if (r2l.count(p)) {
            int l = r2l[p];
            int s = p - l + 1;
            occ[p] = 0;
            pos_bit.add(p, -1);
            empty_bit.add(p, 1);
            total_occ--;
            add_block(s, -1);
            add_block(s - 1, 1);
            r2l.erase(p);
            r2l[p - 1] = l;
            l2r[l] = p - 1;
        } else {
            auto [l, r] = block_of(p);
            int s = r - l + 1;
            occ[p] = 0;
            pos_bit.add(p, -1);
            empty_bit.add(p, 1);
            total_occ--;
            add_block(s, -1);
            add_block(p - l, 1);
            add_block(r - p, 1);
            l2r[l] = p - 1;
            r2l[p - 1] = l;
            l2r[p + 1] = r;
            r2l[r] = p + 1;
            total_blocks++;
        }
    }
    long long top_t_sum(int t) {
        if (t >= total_blocks) return total_occ;
        long long x = total_blocks - t;
        long long s = cnt_bit.find_kth(x) + 1;
        long long cnt_less = cnt_bit.sum(s - 1);
        long long sum_less = sum_bit.sum(s - 1);
        long long need = x - cnt_less;
        return total_occ - (sum_less + need * s);
    }
};

long long solve_case(vector<long long>& a, int m, int k) {
    int n = (int)a.size();
    if (k == 1) return 0;
    vector<long long> b = a;
    sort(b.begin(), b.end());
    if (m >= k - 1) {
        long long g = LLONG_MAX;
        for (int i = 0; i + k - 1 < n; i++)
            g = min(g, b[i + k - 1] - b[i]);
        return g;
    }
    map<long long, vector<int>> pos_of_val;
    for (int i = 0; i < n; i++) pos_of_val[a[i]].push_back(i);
    map<long long, int> cnt_val;
    PosBlock pb(n);
    int j = -1;
    long long ans = -1;
    int t = m + 1;
    for (int i = 0; i < n; i++) {
        if (j < i) j = i - 1;
        while (j + 1 < n && pb.top_t_sum(t) < k) {
            long long v = b[j + 1];
            cnt_val[v]++;
            if (cnt_val[v] == 1) {
                for (int p : pos_of_val[v]) pb.insert(p);
            }
            j++;
        }
        if (pb.top_t_sum(t) >= k) {
            long long d = b[j] - b[i];
            if (ans < 0 || d < ans) ans = d;
        }
        long long v = b[i];
        cnt_val[v]--;
        if (cnt_val[v] == 0) {
            for (int p : pos_of_val[v]) pb.remove(p);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve_case(a, m, k) << '\n';
    }
    return 0;
}
