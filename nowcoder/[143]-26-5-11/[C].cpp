#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9+7;
int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res%mod;
}
void solve() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    vector<int> v1, v2;
    for (int i = 1; i < sqrt(x); ++i) {
        if (x%i == 0) {
            v1.push_back(i);
            v1.push_back(x/i);
        }
    }
    for (int i = 1; i < sqrt(y); ++i) {
        if (y%i == 0) {
            v2.push_back(i);
            v2.push_back(y/i);
        }
    }
    // v1.erase(unique(v1.begin(), v1.end()));
    // v2.erase(unique(v2.begin(), v2.end()));
    int t = v1.size();
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < v2.size(); ++j) {
            v1.push_back(v1[i]*v2[j]);
        }
    }
    v1.insert(v1.end(), v2.begin(), v2.end());
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    for (auto&i : v1) {
        ans += qpow(i, i);
        ans %= mod;
    }
    cout << ans%mod;
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