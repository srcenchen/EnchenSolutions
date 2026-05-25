#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// // 堆优化版本 超时
// void solve() {
//     int n; cin >> n;
//     vector<int> nums(n+1);
//     for (int i = 1; i <= n ;++i) {
//         cin >> nums[i];
//     }
//     // 双向图 邻接表
//     vector<vector<pair<int, int>>> grap(n+1); // 权值、点
//     for (int i = 1; i <= n; ++i) {
//         for (int j = i+1; j <= n; ++j) {
//             int t;
//             if ((i+j)&1) {
//                 // 奇数
//                 t = nums[(i+j)/2] + nums[(i+j+2)/2];
//             } else {
//                 // 偶数
//                 t = nums[(i+j)/2] * 2;
//             }
//             grap[i].push_back({t, j});
//             grap[j].push_back({t, i});
//         }
//     }
//     // 图构建完毕，开始MST Prime算法
//     vector<bool> vis(n+1, false);
//     vector<int> dis(n+1, 1e18);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     dis[1] = 0;
//     pq.push({0, 1});
//     int res = 0;
//     int cnt = 0;
//     while (!pq.empty()) {
//         if (cnt >= n) break;
//         auto [w, v] = pq.top();
//         pq.pop();
//         if (vis[v]) continue;
//         vis[v] = 1;
//         res += w;
//         cnt++;
//         for (auto& [ww, vv] : grap[v]) {
//             if (ww < dis[vv]) {
//                 dis[vv] = ww;
//                 pq.push({ww, vv});
//             }
//         }
//     }
//     cout << res << endl;
// }

// Prim 朴素
void solve() {
    int n; cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n ;++i) {
        cin >> nums[i];
    }
    // 开始MST Prime算法
    vector<bool> vis(n+1, false);
    vector<int> dis(n+1, 1e18);
    dis[1] = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (u == -1 || dis[j] < dis[u])) {
                u = j;
            }
        }
        res += dis[u];
        vis[u] = true;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j]) {
                int t;
                if ((u+j)&1) {
                    // 奇数
                    t = nums[(u+j)/2] + nums[(u+j+2)/2];
                } else {
                    // 偶数
                    t = nums[(u+j)/2] * 2;
                }
                if (t < dis[j]) {
                    dis[j] = t;
                }
            }
        }
    }
    cout << res << endl;
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