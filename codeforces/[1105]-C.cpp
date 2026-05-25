#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD = 1e9+7;
void solve() {
    int n, l, r; cin >>n >>l>>r;
    int mod0 = r/3 - (l-1)/3;
    int mod1 = (r+2)/3 - (l+1)/3;
    int mod2 = (r+1)/3 - l/3;
    // cout << mod0 << " " << mod1 << " " << mod2;
    vector<vector<int> > dp(n+1, vector<int>(3));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][0] * mod0 % MOD + 
                    dp[i - 1][1] * mod2 % MOD + 
                    dp[i - 1][2] * mod1 % MOD) % MOD;
        
        // 更新余数为 1 的情况
        dp[i][1] = (dp[i - 1][0] * mod1 % MOD + 
                    dp[i - 1][1] * mod0 % MOD + 
                    dp[i - 1][2] * mod2 % MOD) % MOD;
        
        // 更新余数为 2 的情况
        dp[i][2] = (dp[i - 1][0] * mod2 % MOD + 
                    dp[i - 1][1] * mod1 % MOD + 
                    dp[i - 1][2] * mod0 % MOD) % MOD;
    }
    cout << dp[n][0];
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