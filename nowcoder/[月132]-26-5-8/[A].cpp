#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int check(int n) {
    if (n >= 2800) {
        return 6;
    } else if (n >= 2400) {
        return 5;
    } else if (n >= 2000) {
        return 4;
    } else if (n >= 1500) {
        return 3;
    } else if (n >= 1100) {
        return 2;
    } else if (n >= 700) {
        return 1;
    } else {
        return 0;
    }
}
int tot = 1000;
vector<int> cnt(7);
void solve() {
    int n; cin >> n;
    cnt[check(n+tot)]++;
    tot += n;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    for (auto& i : cnt) {
        cout << i << " ";
    }
    return 0;
}