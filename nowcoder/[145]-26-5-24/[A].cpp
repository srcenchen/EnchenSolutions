#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str;
    cin >> str;
    unordered_map<char, int> cnt;
    for (auto& i : str) {
        cnt[i]++;
    }
    if (cnt.size()==2) {
        cout << "Yes";
    } else {
        cout << "No";
    }
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