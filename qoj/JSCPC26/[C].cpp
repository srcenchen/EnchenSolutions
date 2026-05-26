#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int cnt1 = 0;
    for (auto& i : str) {
        if (i == '1') {
            cnt1++;
        }
    }
    string end = "&";
    if (cnt1 == n) {
        end = "^";
    }
    for (int i = 0 ; i < n-2; ++i) {
        cout << "&";
    }
    cout << end;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}