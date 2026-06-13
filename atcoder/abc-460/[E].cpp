#include <bits/stdc++.h>
using namespace std; 
#define int unsigned long long
#define endl "\n"

const int MOD = 998244353;
int p10[20]; 

void init() {
    p10[0] = 1;
    for (int i = 1; i <= 19; i++) {
        p10[i] = p10[i - 1] * 10;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int d = 1; d <= 19; d++) {
        int L = p10[d - 1];
        int R = min(p10[d], n + 1);
        if (L >= R) break;
        int g = gcd(p10[d] - 1, m);
        int count_y = (R - L) % MOD;
        int count_x = (n / (m / g)) % MOD;
        ans = (ans + count_y * count_x) % MOD;
    }
    
    cout << ans << endl;
}

signed main() {
    init(); 
    
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}