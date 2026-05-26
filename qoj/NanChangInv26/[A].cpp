#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    if (a % b) {
        cout << 0;
    } else {
        cout << 1;
    }
    cout << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}