#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pd;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pd.push_back({a-k, 1});
        pd.push_back({b+1, -1});
    }
    sort(pd.begin(), pd.end());
    int ans = 0;
    int i = 0, tmp = 0;
    while (i < pd.size()) {
        int pos = pd[i].first;
        while (i < pd.size() && pos == pd[i].first) {
            tmp += pd[i].second;
            i++;
        }
        ans = max(ans, tmp);
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