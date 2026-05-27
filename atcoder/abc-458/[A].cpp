#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    string str;
    cin >> str >> n;
    str.erase(str.begin(), str.begin() + n);
    str.erase(str.end()-n, str.end());
    cout << str;
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