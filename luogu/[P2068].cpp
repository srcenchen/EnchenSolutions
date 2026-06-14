#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl
struct BitTree {
    int n; vector<int> tree;
    BitTree(int x) : n(x), tree(n+ 1, 0) {}
    void add(int x, int val) {
        for (int i = x; i <= n; i += i&(-i)) {
            tree[i] += val;
        }
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= i&(-i)) {
            res += tree[i];
        }
        return res;
    }
    int querySum(int l, int r) {
        debug(query(r));
        return query(r) - query(l-1);
    }
};
void solve() {
    int n, w;
    cin >> n >> w;
    BitTree bt(n);
    while (w--) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if (a == 'x') {
            bt.add(b, c);
        } else {
            cout << bt.querySum(b, c) << endl;
        }
    }
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