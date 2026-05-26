#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int p[200005];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> grids(m);
    for (int i = 0; i < m; ++i) {
        cin >> grids[i][0] >> grids[i][1] >> grids[i][2];
    }
    int route[3][2] = {{0, 1}, {1, 2}, {0, 2}};
    for (int i = 0; i < 3; ++i) {
        int c1 = route[i][0], c2 = route[i][1];
        int cc1 = 0, cc2 = 0;
        vector<vector<int>> ans;
        // 初始化病拆机
        for (int j = 1; j <= n; ++j) {
            p[j] = j;
        }
        for (auto& e : grids) {
            if (e[2] == c1) {
                int rx = find(e[0]), ry = find(e[1]);
                if (rx != ry) {
                    p[rx] = ry;
                    ans.push_back({e[0], e[1]});
                    cc1++;
                    break; 
                }
            }
        }
        for (auto& e : grids) {
            if (e[2] == c2) {
                int rx = find(e[0]), ry = find(e[1]);
                if (rx != ry) {
                    p[rx] = ry;
                    ans.push_back({e[0], e[1]});
                    cc2++;
                    break; 
                }
            }
        }
        for (auto& e : grids) {
            if (e[2] == c1 || e[2] == c2) {
                int rx = find(e[0]), ry = find(e[1]);
                if (rx != ry) {
                    p[rx] = ry;
                    ans.push_back({e[0], e[1]});
                    if (e[2] == c1) cc1++;
                    else cc2++;
                }
            }
        }
        if (ans.size() == n - 1 && cc1 > 0 && cc2 > 0) {
            for (auto& i : ans) {
                cout << i[0] << " " << i[1] << endl;
            }
            return;
        }
    }
    cout << -1 << endl;
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