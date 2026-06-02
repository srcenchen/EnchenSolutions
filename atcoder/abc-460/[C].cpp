#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<int> rice(n), pei(m);
    for (int i = 0; i < n; ++i) {
        cin >> rice[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> pei[i];
    }
    sort(rice.begin(), rice.end());
    sort(pei.begin(), pei.end());
    int r = rice.size()-1, p = pei.size()-1;
    while (r >= 0 && p >= 0) {
        if (2*rice[r] >= pei[p]) {
            ans++;
            r--;
        }
        p--;
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