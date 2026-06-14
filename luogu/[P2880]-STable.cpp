#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int k = log2(n);
    vector<vector<int>> stMax(n, vector<int>(k + 1)), stMin(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i) {
        stMax[i][0] = nums[i];
        stMin[i][0] = nums[i];
    }
    // 构建st
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            // 从i开始 向后推 2 ^ (j - 1)
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto getMax = [&](int l, int r) {
        int m = log2(r - l + 1);
        return max(stMax[l][m], stMax[r - (1 << m) + 1][m]);
    };
    auto getMin = [&](int l, int r) {
        int m = log2(r - l + 1);
        return min(stMin[l][m], stMin[r - (1 << m) + 1][m]);
    };
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int maxx = getMax(l, r);
        int minn = getMin(l, r);
        cout << maxx - minn << endl;
    }
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