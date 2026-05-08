#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 1e9+7;
void solve() {
    int n, k, d;
    cin >> n >> k >>d;
    vector<vector<int> > dp(n+1, vector<int>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int w = 1; w <= k; ++w) {
            if (i + w > n) continue;
            if (w >= d) {
                dp[i+w][1] = (dp[i+w][1]%MOD + dp[i][1]%MOD)%MOD;
                dp[i+w][1] = (dp[i+w][1]%MOD + dp[i][0]%MOD)%MOD;
            } else {
                dp[i+w][0] = (dp[i+w][0]%MOD + dp[i][0]%MOD)%MOD;
                dp[i+w][1] = (dp[i+w][1]%MOD + dp[i][1]%MOD)%MOD;
            }
        }
    }
    cout << dp[n][1];
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