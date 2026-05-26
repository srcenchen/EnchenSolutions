#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string str = "HelloWorld";
    int x;
    cin >> x;
    str.erase(str.begin() + x - 1);
    cout << str;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}