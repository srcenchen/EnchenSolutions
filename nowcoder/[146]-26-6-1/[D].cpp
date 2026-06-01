#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
const int MOD = 998244353;
void solve() {
    int n; cin >> n;
    string str; cin >> str;
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = str[i-1] - '0';
        for (int j = 0; j < 3; ++j) {
            int prev = (j - x%3 + 3) % 3;
            dp[i][j] = dp[i-1][prev]% MOD + dp[i-1][j]% MOD;
            dp[i][j] %= MOD;
        }
        if (x % 2 == 0) {
            ans = (ans + dp[i][0] - dp[i-1][0] + MOD) % MOD;    
        }
    }
    cout << ans % MOD;
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