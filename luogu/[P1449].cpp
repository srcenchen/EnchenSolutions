#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string str;
    cin >> str;
    stack<int> st;
    string tmp;
    for (auto& i : str) {
        if (i >= '0' && i <= '9') {
            tmp += i;
        } else if (i == '.') {
            st.push(stoi(tmp));
            tmp = "";
        } else if (i != '@') {
            // get front 2 and run op
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            switch (i) {
            case '+':
                b += a;
                break;
            case '-':
                b -= a;
                break;
            case '*':
                b *= a;
                break;
            case '/':
                b /= a;
                break;
            }
            st.push(b);
        }
    }
    cout << st.top();
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