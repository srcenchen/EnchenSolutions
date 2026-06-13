#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve() {
    int a, d;
    cin >> a >> d;
    if (a <= d) {
        cout << "Yes";
    }
    else
    cout << "No";
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}