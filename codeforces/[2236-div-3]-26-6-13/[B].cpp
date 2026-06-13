#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
#define debug(x) cerr << #x << " = " << (x) << endl

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    str = " " + str;
    auto swit = [&](int x) {
        if (str[x] == '0') str[x] = '1';
        else str[x] = '0';
    };
    for(int i = 1; i <= n-k; ++i) {
        if (str[i] == '1') {
            swit(i);
            swit(i+k);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (str[i] == '1') {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}