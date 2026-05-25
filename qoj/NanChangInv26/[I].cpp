#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int l, d;
    int t[3];
    cin >> l >> d >> t[0] >> t[1]>>t[2];
    string pla;
    cin >> pla;
    vector<vector<int>> dp(l+d+1, vector<int>(4, 0x3f3f3f33f3f3f));
    dp[0][0] = 0;
    for (int i = 1; i <= l; ++i) {
        for (int j = 0; j <= 3; ++j) {
            dp[i][j] = dp[i-1][0] + t[pla[i-1]-'0'];
        }

    }
    for (int i = 1; i <= l+d; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (i-d >= 0) {
                int tp = (i > l) ? 0 : t[pla[i-1]-'0'];
                //cout << dp[i-1][j]+tp << " " << dp[i-d][j-1] << endl;
                dp[i][j] = min(dp[i-1][j]+tp, dp[i-d][j-1]);
            }
        }
    }
    int ans = LLONG_MAX;
    for (int i = l; i <= l+d; ++i) {
        for (int j = 0; j <= 3; ++j) {
            ans = min(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

signed main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}