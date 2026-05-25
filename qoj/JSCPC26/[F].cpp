#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " :" << x << "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> cnt;
    int mod = 0;
    int cntMin = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        cnt[nums[i]]++;
        mod = max(mod, nums[i]);
        cntMin = min(cntMin, nums[i]);
    }
    mod++;
    // 探测是否中断
    for (int i = 0; i < cnt.size(); ++i) {
        if (!cnt.count(i)) {
            cout << max(i, cntMin);
            return;
        }
    }
    int ans1 = cnt.size()+1;
    pair<int, int> pa = {-1, INT_MAX};
    for (auto& [k, v] : cnt) {
        if (v-1 <= pa.second) {
            pa = {k, v-1};
        }
    }
    int ans2 = mod + mod*pa.second + pa.first;
    cout << max(ans1, ans2);
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