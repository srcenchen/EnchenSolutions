#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl
struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int x) : n(x), tree(n+1, 0) {}
    void add(int x, int val) {
        for (; x <= n; x += x&-x) {
            tree[x] += val;
        }
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= i&(-i)) {
            res += tree[i];
        }
        return res;
    }
};
void solve() {
    int n;
    cin >> n;
    FenwickTree tree(n);
    vector<int> nums(n+1);
    vector<int> m(n);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        m[i-1] = nums[i];
    }
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        int pos = lower_bound(m.begin(), m.end(), nums[i]) - m.begin() + 1;
        int q = tree.query(pos-1);
        // debug(q);
        ans += q;
        tree.add(pos, 1);
    }
    cout << ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}