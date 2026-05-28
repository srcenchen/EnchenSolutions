#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
// 二分答案
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int l = -1, r = 1e18+7;
    auto check = [&](int r)-> bool {
        int needK = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < r) {
                int needNum = r - nums[i];
                int need = (needNum + i) / (i+1);
                needK += need;
            }
            if (needK > k) {
                return false;
            }
        }
        return needK <= k;
    };
    int left = -1, right = 9e18;
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}