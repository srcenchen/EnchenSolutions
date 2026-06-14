#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl
struct FenwickRMQ {
    vector<int> treeMax,treeMin;
    int n;
    vector<int> nums;
    FenwickRMQ(vector<int> nums) : n(nums.size()-1), treeMax(nums.size(), INT_MIN), treeMin(nums.size(), INT_MAX), nums(nums) {
        for (int i = 1; i <= n; ++i) {
            add(i, nums[i]);
        }
    }
    void add(int x, int val) {
        for (int i = x; i <= n; i += i&(-i)) {
            treeMax[i] = max(treeMax[i], val);
            treeMin[i] = min(treeMin[i], val);
        }
    }
    int lowbit(int x) {
        return x & (-x);
    }
    int queryMin(int l, int r) {
        if (r > l) {
            if (r - lowbit(r) >= l) return min(queryMin(l, r - lowbit(r)), treeMin[r]);
            else return min(nums[r], queryMin(l, r-1));
        } else {
            return nums[l];
        }
    }
    int queryMax(int l, int r) {
        if (r > l) {
            if (r - lowbit(r) >= l) return max(queryMax(l, r - lowbit(r)), treeMax[r]);
            else return max(nums[r], queryMax(l, r-1));
        } else {
            return nums[l];
        }
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    FenwickRMQ tree(nums);
    while (q--) {
        int l, r;cin >> l >> r;
        int a = tree.queryMax(l, r);
        int b = tree.queryMin(l, r);
        cout << a - b << endl;
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