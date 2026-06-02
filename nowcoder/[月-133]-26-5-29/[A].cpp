#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str; cin >> str;
    if (str == "awdec")
        cout << "Fantasy_Blue";
    else if (str == "Fantasy_Blue") cout << "awdec";
    else cout << "other";
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