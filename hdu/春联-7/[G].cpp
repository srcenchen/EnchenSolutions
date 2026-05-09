#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> min_dist(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    int ans = 0;
    min_dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (u == -1 || min_dist[j] < min_dist[u])) {
                u = j;
            }
        }
        vis[u] = true;
        ans += min_dist[u];
        for (int v = 1; v <= n; ++v) {
            if (!vis[v]) {
                int t;
                if ((u + v) & 1) {
                    t = nums[(u + v) / 2] + nums[(u + v + 2) / 2];
                } else {
                    t = nums[(u + v) / 2] * 2;
                }
                min_dist[v] = min(min_dist[v], t);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}