#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    unordered_map<int, vector<int>> X, Y;
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        X[a].push_back(b);
        Y[b].push_back(a);
        cnt[{a, b}]++;
    }
    int ans = 0;
    for (auto& [k, v] : X) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                int x = v[i], y = v[j];
                if (x == y) continue;
                if ((x + y) % 2 != 0) continue;
                ans += Y[(x+y)/2].size();
                ans -= cnt[{k, (x+y)/2}];
            }
        }
    }
    for (auto& [k, v] : Y) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                int x = v[i], y = v[j];
                if (x == y) continue;
                if ((x + y) % 2 != 0) continue;
                ans += X[(x+y)/2].size();
                ans -= cnt[{(x+y)/2, k}];
            }
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