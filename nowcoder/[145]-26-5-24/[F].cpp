#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    int x = k+2-n;
    vector<int> ans(n+1);
    ans[1] = 4;
    int cur = 2;
    while (x--) {
        ans[cur++] = 1;
    }
    ans[cur++] = 2;
    for (; cur <= n; ++cur) {
        ans[cur] = 3;
    }
    for (int k = 1; k <= n; ++k) {
        int i = ans[k];
        cout << char(i-1+'a');
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}