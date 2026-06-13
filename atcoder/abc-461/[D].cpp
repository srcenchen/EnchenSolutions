#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grids(h);
    for (int i = 0; i < h; ++i) {
        cin >> grids[i];
    }
    vector<vector<int>> prefix(h+1, vector<int>(w+1));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grids[i-1][j-1] - '0';
        }
    }
    vector<int> prefixCnt(h*w+1, 0);
    int ans = 0;
    for (int r1 = 1; r1 <= h; ++r1) {
        for (int r2 = r1; r2 <= h; ++r2) {
            prefixCnt[0] = 1;
            for (int i = 1; i <= w; ++i) {
                int cur = prefix[r2][i] - prefix[r1-1][i];
                if (cur >= k) {
                    ans += prefixCnt[cur - k];
                }
                prefixCnt[cur]++;
            }
            for (int i = 1; i <= w; ++i) {
                int cur = prefix[r2][i] - prefix[r1-1][i];
                prefixCnt[cur] = 0;
            }
        }
    }
    cout << ans;
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