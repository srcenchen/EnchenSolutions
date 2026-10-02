#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 10000;
void solve() {
    stack<int> st;
    int a, b;
    char op;
    cin >> a;
    a %= mod;
    st.push(a);
    while (cin >> op >> a) {
        if (op == '*') {
            int top = st.top();
            st.pop();
            top *= a % mod;
            top %= mod;
            st.push(top);
        } else {
            st.push(a % mod);
        }
    }
    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
        ans %= mod;
    }
    cout << ans;
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