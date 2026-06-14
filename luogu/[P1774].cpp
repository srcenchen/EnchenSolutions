#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl
struct BitTree {
    int n; vector<int> tree;
    BitTree(int x) : n(x), tree(x+1, 0) {}
    void add(int x, int val) {
        for (int i = x; i <= n; i += i&-i) {
            tree[i] += val;
        }
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= i&-i) {
            res += tree[i]; 
        }
        return res;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        m[i] = nums[i];
    }
    BitTree bt(n);
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        int pos = lower_bound(m.begin(), m.end(), nums[i]) - m.begin() + 1;
        ans += bt.query(pos-1);
        bt.add(pos, 1);
    }
    cout << ans;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}