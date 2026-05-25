#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;cin >> n;
    if (n+n-1 < 1e18) {
        cout << n << " " << n+n-1;
    } else {
        cout << n-n+1 << " " << n;
    }
    
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