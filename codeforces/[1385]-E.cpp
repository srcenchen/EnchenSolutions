#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> pos(n+1);
    vector<array<int, 2>> noneG;
    vector<int> in(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >>c;
        if (a) {
            g[b].push_back(c);
            in[c]++;
        } else {
            noneG.push_back({b, c});
        }
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            que.push(i);
        }
    }
    int idx = 0;
    while (!que.empty()) {
        int c =que.front();
        que.pop();
        pos[c] = ++idx;
        for (auto& i : g[c]) {
            if (--in[i] == 0) {
                que.push(i);
            }
        }
    }
    if (idx != n) {
        // 出现环
        cout << "NO" << endl;
        return;
    }
    for (auto& [a, b] : noneG) {
        if (pos[a] > pos[b]) {
            // 谁小谁是父亲，因为入度少
            g[b].push_back(a);
        } else {
            g[a].push_back(b);
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() != 0) {
            for (auto& k : g[i]) {
                cout << i << " " << k << endl;
            }
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}