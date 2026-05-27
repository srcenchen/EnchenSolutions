#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str; cin >> str;
    int n = str.size();
    // find C
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'C') {
            pos.push_back(i);
        }
    }
    int ans = pos.size();
    int mid = (n + 1) /2;
    for (auto& i : pos) {
        int t = i+1;
        if (t <= mid) {
            ans += t-1;
        } else {
            ans += (n-t);
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