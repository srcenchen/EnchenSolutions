#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<vector<int> > grids(n+1, vector<int>(n+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> grids[i][j];
    }
    vector<vector<bool> > rowHas(n, vector<bool>(n*n+1)), colHas(n, vector<bool>(n*n+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rowHas[i][grids[i][j]] = true;
            colHas[j][grids[i][j]] = true;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n*n+1; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (!rowHas[j][i] || !colHas[j][i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;

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