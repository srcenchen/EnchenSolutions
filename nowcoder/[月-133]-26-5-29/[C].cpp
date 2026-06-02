#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;cin >> n >> k;
    string str;
    cin >> str;
    bool flagA = false, flagB = false;
    string A = "awdec", B = "Fantasy_Blue";
    for (int i = 0; i < n; ++i) {
        int p = 0, cur = i;
        int times = 0;
        bool* flag;
        if (str[i] == 'a' && !flagA) {
            times = A.size() + k;
            flag = &flagA;
        } else if (str[i] == 'F' && !flagB) {
            times = B.size() + k;
            flag = &flagB;
        }
        while (times-- && cur < n) {
            if (str[cur++] == A[p]) {
                p++;
            }
            if (p == A.size()) {
                *flag = true;
                break;
            }
        }
    }
    if (flagA && flagB) {
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