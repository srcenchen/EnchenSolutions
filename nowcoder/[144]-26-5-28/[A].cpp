#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    string str; cin >> str;
    unordered_map<char, int> cnt;
    for (auto& i : str) {
        cnt[i]++;
    }
    int last = -1;
    for (auto& [k, v] : cnt) {
        if (last == -1) {
            last = v;
        } else if (last != v) {
            cout << "No";
            return;
        }
    }
    if (cnt.size() != 4) {
        cout << "No";
        return;
    }
    cout << "Yes";
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