#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int dis(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
void solve() {
    int x1, y1, r1, x2 ,y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int R = (r1+r2)*(r1+r2);
    int di = dis(x1, y1, x2, y2);
    if (di < (min(r1, r2)-max(r1,r2))*(min(r1, r2)-max(r1,r2))) {
        cout << "No" << endl;
        return;
    }
    if (di <= R) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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