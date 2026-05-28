#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        while (t--) {
            int c; cin >> c;
            nums[i].push_back(c);
        }
    }
    int x, y;
    cin >> x >> y;
    cout << nums[x-1][y-1];
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