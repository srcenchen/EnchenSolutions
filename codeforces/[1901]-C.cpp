#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    int mmin = INT_MAX, mmax = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        mmin = min(mmin, nums[i]);
        mmax = max(mmax, nums[i]);
    }
    vector<int> ans;
    while (mmin != mmax) {
        if (mmin & 1) {
            mmin = (mmin+1) >> 1;
            mmax = (mmax+1) >> 1;
            ans.push_back(1);
        } else {
            mmin = mmin >> 1;
            mmax = mmax >> 1;
            ans.push_back(0);
        }
    }
    cout << ans.size() << endl;
    if (ans.size() > n) {
        
    } else {
        for (auto& i : ans) {
            cout << i << " ";
        }
    }
    cout << endl;
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