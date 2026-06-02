#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    map<int, int, greater<int>> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    for (auto& [k, v] : cnt) {
        if (v & 1) {
            cout << "red" << endl;
            return;
        }
    }
    cout << "fang" << endl;

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