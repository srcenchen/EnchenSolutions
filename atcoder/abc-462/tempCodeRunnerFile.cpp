#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct FenwickTree {
    vector<int> tree;
    int n;
    FenwickTree(int x) : n(x), tree(x+1, 0) {}
    void add(int x, int val) {
        for (int i = x; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= i&(-i)) {
            ans += tree[i];
        }
        return ans;
    }
};

void solve() {
    int N, D;
    cin >> N >> D;
    vector<int> in(1e6+7);
    vector<vector<int>> p(1e6+7);
    FenwickTree ft(1e6+7);
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        if (r - l < D) continue;
        p[r].push_back(l);
        in[l]++;
    }
    int ans = 0;
    for (int i = 1; i < 1e6+7; ++i) {
        ft.add(i, in[i]);
        int cur = ft.query(i-D);
        ans += (cur-1)*cur/2;
        for (auto& j : p[i]) {
            ft.add(j, -1);
        }
    }
    cout << ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}