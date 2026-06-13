#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl

void solve() {
    int N; cin >> N;
    vector<vector<int>> g(N+1, vector<int>());
    for (int i = 1; i <= N; ++i) {
        int k; cin >> k;
        while (k--) {
            int a; cin >> a;
            g[a].push_back(i);
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << g[i].size() << " ";
        for (auto& i : g[i]) {
            cout << i << " ";
        }
        cout << endl;
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