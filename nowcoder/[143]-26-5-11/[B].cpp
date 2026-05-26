#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m , x;
    cin >> n >> m >>x;
    unordered_map<int, int> nums;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        nums[t]++;
    }
    int ans = m-nums.size();
    for (auto& [k, i] : nums) {
        if (i <= x) {
            ans++;
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