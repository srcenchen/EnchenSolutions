#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    unordered_map<int, int> cnt;
    string str;
    cin >> str;
    int ans = 0;
    for (auto& i : str) {
        cnt[i]++;
    }
    for (auto& i : cnt) {
        if (i.second == 1) ans ++;
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