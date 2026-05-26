#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string ans;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        char a = s[0];
        if (a <= 'o') {
            ans += (a-'a') / 3 + '0' + 2;
        } else if (a <= 's') {
            ans += '7';
        } else if (a <= 'v') {
            ans += '8';
        } else {
            ans += '9';
        }
    }
    cout << ans;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}