#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n+1, 0) {}
    void add(int val, int index) {
        for (int i = index; i <= n; i += i&-i) {
            tree[i] += val;
        }
    }
    int query(int index) {
        int res = 0;
        for (int i = index; i >= 1; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    BIT bitR(q+1);
    BIT bitC(q+1);
    bitR.add(n, 1);
    bitC.add(n, 1);
    vector<int> TR(n+1, 0), TC(n+1, 0);
    int ans = 0;
    for (int t = 1; t <= q; ++t) {
        int op, idx;
        cin >> op >> idx;

        if (op == 1) {
            int old = TR[idx];
            ans += n - bitC.query(old);
            TR[idx] = t;
            bitR.add(-1, old+1);
            bitR.add(1, t+1);
        } else {
            int old = TC[idx];
            ans -= n - bitR.query(old+1);
            TC[idx] = t;
            bitC.add(-1, old+1);
            bitC.add(1, t+1);
        }
        cout << ans << endl;
    }
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