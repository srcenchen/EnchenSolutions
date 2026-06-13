#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl

void solve() {
    string str;
    cin >> str;
    string ans;
    for (auto& i : str) {
        if (i >= '0' && i <= '9') {
            ans += i;
        }
    }
    cout << ans;
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