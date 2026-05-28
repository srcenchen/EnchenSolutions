#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> height(n+1);
    vector<vector<array<int, 2>>> edges(n+1);
    vector<array<int, 2>> points(n+1);
    vector<int> ans(n+1);
    for (int i = 1; i <= n; ++i) cin >> height[i];
    for (int i = 2; i <= n; ++i) {
        cin >> points[i][0];
    }
    for (int i = 2; i <= n; ++i) {
        cin >> points[i][1];
    }
    for (int i = 2; i <= n; ++i) {
        edges[points[i][0]].push_back({i, points[i][1]});
    }
    auto dfs = [&](auto&& dfs, int x, int t)->int {
        // is root
        if (edges[x].size() == 0) {
            // cout << height[x] << endl;
            return height[x];
        }
        sort(edges[x].begin(), edges[x].end(), [](const array<int, 2>& a, const array<int, 2>& b) {
            return a[1] < b[1];
        });
        int a = 0;
        for (auto& i : edges[x]) {
            int tmp = dfs(dfs, i[0], t+i[1]);
            ans[i[0]] = tmp + i[1] + t;
            t += tmp;
            a += tmp;
        }
        a += height[x];
        return a;
    };
    ans[1] = dfs(dfs, 1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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