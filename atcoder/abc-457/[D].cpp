#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
// TLE 优先队列做法 因为 K->1e18
struct node {
    int val, index;
    bool operator< (const node& b) const {
        if (val == b.val) {
            return index < b.index;
        }
        return val > b.val;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<node> pq;
    for (int i = 1; i <= n; ++i) {
        int t; 
        cin >> t;
        pq.push({t, i});
    }
    while (k) {
        auto [v, i] = pq.top();
        // cout << v << " " << i << endl;
        pq.pop();
        int newV = v+i;
        if (!pq.empty()) {
            int secSmall = pq.top().val;
            int z = secSmall - v;
            int cx = (z + i) / i;
            newV = v + i*min(k, cx);
            k = k - min(k, cx) + 1;
        }
        pq.push({newV, i});
        k--;
    }
    cout << pq.top().val;
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