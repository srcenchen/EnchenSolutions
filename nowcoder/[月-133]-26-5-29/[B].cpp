#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    // if (n>1) {
    //     cout << 2;
    // } else {
    //     cout << 1;
    // }
    // cout << endl;
    int l = 1, r = n;
    while (l <= r) {
        cout << l++ << " ";
        if (l-1 != r) {
            cout << r-- << " ";
        }
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}