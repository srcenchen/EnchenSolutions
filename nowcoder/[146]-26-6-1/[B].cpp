#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    int ans = abs(k);
    while (n--) {
        int a, b;
        cin >> a >> b;
        int t = abs(a);
        t += abs(k-b);
        ans = min(ans, t);
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