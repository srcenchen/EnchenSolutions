#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, a, b, c;
    cin >>n>>a>>b>>c;
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        bool f = false;
        if (i-a >= 0 && dp[i-a] >= 0) {
            dp[i] = max(dp[i], dp[i-a]+1);
            f = true;
        }
        if (i-b >= 0 && dp[i-b] >= 0) {
            dp[i] = max(dp[i], dp[i-b]+1);
            f = true;
        }
        if (i-c >= 0 && dp[i-c] >= 0) {
            dp[i] = max(dp[i], dp[i-c]+1);
            f = true;
        }
        if (!f) dp[i] = -1;
    }
    cout << dp[n];
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