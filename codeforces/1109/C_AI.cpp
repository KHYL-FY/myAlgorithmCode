#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int g = gcd(x, y);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            // 当前位置是 i（0-based），元素值是 p[i]，目标位置是 p[i]-1（0-based）
            if ((i % g) != ((p[i] - 1) % g)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}