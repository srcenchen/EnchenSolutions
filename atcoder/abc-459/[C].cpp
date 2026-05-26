#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_VAL = 300005;
int tree[MAX_VAL], cnt[MAX_VAL];
int lowBit(int x) {
    return x & -x;
}

void add(int idx, int val) {
    idx++;
    for (; idx <= MAX_VAL; idx += lowBit(idx)) {
        tree[idx] += val;
    }
}

int query(int idx) {
    idx++;
    int sum = 0;
    for (; idx > 0; idx -= lowBit(idx)) {
        sum += tree[idx];
    }
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> P(n+1, 0);
    int c = 0;
    // 初始化 tree
    for (int i = 1; i <= n; ++i) {
        add(0, 1);
        cnt[0]++;
    }
    while (q--) {
        int op; cin >> op;
        int num; cin >> num;
        if (op == 1) {
            int old = P[num];
            add(old, -1);
            add(old+1, 1);
            cnt[old]--;
            cnt[old+1]++;
            P[num]++;
            if (old == c && cnt[old] == 0) {
                c++;
            }
        } else {
            num += c;
            if (num > MAX_VAL) {
                cout << 0 << endl;
            } else {
                int ans = query(num-1);
                cout << n - ans << endl;
            }
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}