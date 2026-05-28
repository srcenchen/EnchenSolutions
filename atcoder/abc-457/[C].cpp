#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; ++i) {
        int l;cin >> l;
        nums[i] = vector<int>(l);
        for (int k = 0; k < l; ++k) {
            cin >> nums[i][k];
        }
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (k - cur <= t*nums[i].size()) {
            int z = k - cur;
            int c = z%(nums[i].size());
            if (c == 0) {
                c = nums[i].size();
            }
            cout << nums[i][c-1];
            return;
        } 
        cur += t*nums[i].size();
        // cout << cur << endl;
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