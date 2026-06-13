#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl
int c2(int x) {
    if (x < 2) return 0;
    return x * (x - 1) / 2;
}
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> diff(1e6+7, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (b-a < d) continue;
        diff[a]++;
        diff[b-d+1]--;
    }
    vector<int> nums(1e6+7);
    for (int i = 1; i < 1e6+7; ++i) {
        nums[i] = nums[i-1] + diff[i];
    }
    int ans = 0;
    for (int i = 1; i < 1e6+7; ++i) {
        // debug(nums[i]);
        ans += c2(nums[i]);
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