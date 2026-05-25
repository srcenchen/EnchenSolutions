#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int ans = 0;
    int lastPos = -1;
    for (int r = 0; r < str.size();++r) {
        if (r > 0 && str[r] != str[r - 1]) {
            lastPos = r - 1;
        }
        if (lastPos != -1) {
            ans += (lastPos + 1);
        }
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