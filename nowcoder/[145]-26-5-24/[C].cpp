#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int blue = 0, red = 0;
    int blueCnt = 0, redCnt = 0;
    string cor; cin >> cor;
    for (int i = 0; i < n; ++i) {
        if (cor[i] == '1') {
            blue += nums[i];
            blueCnt++;
        } else {
            red += nums[i];
            redCnt++;
        }
    }
    int t1 = red*blueCnt - blue*redCnt;
    int t2 = redCnt + blueCnt;
    if (t1 % t2 == 0) {
        cout << abs(t1/t2);
    } else {
        cout << -1;
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