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
    int n, m;
    cin >> n >> m;
    BitTree bt(n+1); // 这是一个差分数组
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        if (op == 0) {
            int a, b;
            cin >> a >> b;
            bt.add(a, 1);
            bt.add(b+1, -1);
        } else {
            int a;
            cin >> a;
            cout << bt.query(a)<< endl;
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