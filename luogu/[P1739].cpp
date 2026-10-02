#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string str;
    cin >> str;
    stack<char> spa, oth;
    for (auto& i : str) {
        if (i == '(') {
            spa.push('(');
        } else if (i == ')') {
            if (!spa.empty()) {
                spa.pop();
            } else {
                cout << "NO";
                return;
            }
        }
    }
    if (!spa.empty()) {
        cout << "NO";
    } else
    cout << "YES";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}