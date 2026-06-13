#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    vector<int> diff(n+1, 0);
    for (int i = 1; i < n; ++i) {
        diff[i] = ((nums[i+1] - nums[i] + 5) % 5 + 5) % 5;
    }
    int ans = 0;
    for (auto& i : diff) ans += i;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > 1) {
            ans -= diff[a-1];
            diff[a-1] = (diff[a-1] + 1 + 5)%5;
            ans += diff[a-1];
        }
        if (b < n) {
            ans -= diff[b];
            diff[b] = (diff[b] - 1 + 5)%5;
            ans += diff[b];
        }
        cout << ans << endl;
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