#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve() {
    int a, b, x;
    cin >> a >> b >> x;

    map<pair<int, int>, int> cnt;

    auto dfs = [&](auto&& dfs, int a, int b) -> int {
        if (a > b) swap(a, b);
        if (a == b) return 0;
        if (cnt.count({a, b})) {
            return cnt[{a, b}];
        }
        int res = abs(a - b);
        if (b > 0) {
            res = min(res, 1 + dfs(dfs, a, b / x));
            if (a > 0) {
                res = min(res, 2 + dfs(dfs, a / x, b / x));
            }
        }
        cnt[{a, b}] = res;
        return res;
    };

    cout << dfs(dfs, a, b) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}