#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct Node {
    int color, value, idx;
    bool operator< (const Node& other) const {
        return value > other.value;
    }
};
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    int idx = 0;
    unordered_set<int> used;
    unordered_map<int, Node> ma;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        Node d = {a, b, ++idx};
        nodes[i] = d;
        if (ma[a].value < b) {
            ma[a] = d;
        }
    }
    int ans = 0;
    vector<Node> cmm;
    for (auto& i : ma) {
        cmm.push_back(i.second);
    }
    sort(cmm.begin(), cmm.end());
    for (int i = 0; i < m; ++i) {
        ans += cmm[i].value;
        used.insert(cmm[i].idx);
    }
    cmm.clear();
    for (int i = 0; i < n; ++i) {
        if (!used.count(nodes[i].idx)) {
            cmm.push_back(nodes[i]);
        }
    }
    sort(cmm.begin(), cmm.end());
    for (int i = 0; i < k-m; ++i) {
        ans += cmm[i].value;
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