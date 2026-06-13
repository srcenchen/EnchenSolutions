#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int, int>> nums(n);
    for (int i = 0 ; i < n; ++i) {
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums.begin(), nums.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    });
    int point = 0;
    int ans = 0;
    unordered_set<int> cnt;
    for (int i = 0; i < k; ++i) {
        if (m-cnt.size()+1 < k-i) {
            if (cnt.count(nums[point].first)) {
                i--;
                point++;
                continue;
            }
        }
        ans += nums[point].second;
        cnt.insert(nums[point++].first);
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