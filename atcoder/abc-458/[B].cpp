#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int h, w;
    cin >> w >> h;
    int DIRS[4][2] = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= h; ++j) {
            int t = 0;
            for (auto& [mx, my] : DIRS) {
                int a = mx + i, b = my + j;
                if (a >= 1 && b >= 1 && a <= w && b <= h) {
                    t++;
                }
            }
            cout << t << " ";
        }
        cout << endl;
    }
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