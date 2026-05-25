#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    unordered_map<int, int> cnt, dp;
    int mmax = 0;

    for (int i = 0; i < n;++i) {
        int t; cin >>t;
        cnt[t]++;
        mmax = max(mmax, t);
    }
    for (int i = 1; i <= mmax; ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+cnt[i]*i);
    }
    cout << dp[mmax];
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