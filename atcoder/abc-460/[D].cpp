#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    int DIRS[8][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}};
    vector<vector<int>> vis(h+1, vector<int>(w+1, -2));
    int idx = 1;
    queue<array<int, 2>> que;
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == '#') {
                bool can_spread = false;
                for (auto& [mx, my] : DIRS) {
                    int x = i + mx, y = j + my;
                    if (x >= 0 && y >= 0 && x < h && y < w && g[x][y] == '.') {
                        can_spread = true;
                        break;
                    }
                }
                // 只有能扩散的黑块，才是合法的 0 号源点
                if (can_spread) {
                    que.push({i, j});
                    vis[i][j] = idx; 
                }
            }
        }
    }
    while (!que.empty()) {
        int size = que.size();
        auto [i, j] = que.front();
        que.pop();
        for (auto& [mx, my] : DIRS) {
            int x = i + mx, y = j + my;
            if (x >= 0 && y >= 0 && x < h && y < w && vis[x][y] == -2) {
                vis[x][y] = vis[i][j]+1;
                que.push({x, y});
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (vis[i][j] & 1) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
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