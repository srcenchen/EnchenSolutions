#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    unordered_map<char, pair<int, int>> ma;
    for (int i = 1; i <= n; ++i) {
        char a;
        int qa;
        cin >> a >> qa;
        if (ma[a].first < qa) {
            ma[a] = {qa, i};
        }
    }
    int ans = 0;
    vector<int> aaa;
    for (char i = 'A'; i <= 'F'; ++i) {
        if (!ma.count(i)) {
            cout << -1;
            return;
        }
        if (ma[i].first < 60) {
            cout << -1;
            return;
        }
        ans += ma[i].first;
        aaa.push_back(ma[i].second);
    }
    if (ans / 6.0 < 70) {
        cout << -1;
        return;
    }
    for (auto& i : aaa) {
        cout << i << " ";
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