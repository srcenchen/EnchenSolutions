#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ma = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        ma = max(ma, nums[i]);
    }
    int k = 0;
    ma++;
    for (int i = 0; i < n; ++i) {
        k = max(k, abs(nums[i] - ma));
    }
    cout << k << endl;
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