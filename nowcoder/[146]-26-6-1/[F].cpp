#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(14, 0);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        nums[t]++;
    }
    bool useA = a > b;
    int ans = 0;
    for (int i = 1; i <= 11; ++i) {
        int nA = nums[i] / 3, nB = nums[i+1] / 3, nC = nums[i+2] / 3;
        int z = min({nA, nB, nC});
        int c = z / 3;
        if (c == 0) continue;
        ans += (useA) ? a*c*3 : b*c*3;
        nums[i] -= c*9;
        nums[i+1] -= c*9;
        nums[i+2] -= c*9;
    }
    // 兜底
    
    for (int i = 1; i <= 13; ++i) {
        int z = nums[i] / 3;
        // cout << z << endl;
        ans += z*a;
        nums[i] -= z*3;
    }
    for (int i = 1; i <= 11; ++i) {
        int nA = nums[i] / 3, nB = nums[i+1] / 3, nC = nums[i+2] / 3;
        int z = min({nA, nB, nC});
        ans += b*z;
        nums[i] -= z;
        nums[i+1] -= z;
        nums[i+2] -= z;
    }
    cout << ans;
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