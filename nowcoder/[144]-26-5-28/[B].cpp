#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n == 2) {
        cout << "1 2\n" << "3 4";
        return;
    }
    if (n == 3) {
        cout << "1 2 3\n" << "5 4 6\n" << "7 8 9\n";
        return;
    }
    cout << -1;
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