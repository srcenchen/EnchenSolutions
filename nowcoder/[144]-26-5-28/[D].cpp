#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    int len = r-l+1;
    int q = len/k;
    int ren = len%k;
    int less = k-ren;
    int ans = ren*(q+1)*q/2 + less*q*(q-1)/2;
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