#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> preHor(n+1, vector<int>(m+1, 0));
    vector<vector<int>> preVer(n+1, vector<int>(m+1, 0));
    vector<string> grids(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> grids[i];
        grids[i] = " " + grids[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 继承
            preHor[i][j] += preHor[i-1][j] + preHor[i][j-1] - preHor[i-1][j-1];
            preVer[i][j] += preVer[i-1][j] + preVer[i][j-1] - preVer[i-1][j-1];
            if (grids[i][j] == '.') {
                if (grids[i][j-1] == '.') preHor[i][j]++;
                if (grids[i-1][j] == '.') preVer[i][j]++;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ansH = preHor[x2][y2] - preHor[x1-1][y2] - preHor[x2][y1] + preHor[x1-1][y1];
        int ansV = preVer[x2][y2] - preVer[x1][y2] - preVer[x2][y1-1] + preVer[x1][y1-1];
        cout << ansH + ansV << endl;
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