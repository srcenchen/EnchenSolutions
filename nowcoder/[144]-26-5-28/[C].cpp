#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m;
    cin >> n >> m;
    // 最大
    string minN, maxN, minM, maxM;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            minN += '1';
        } else {
            minN += '0';
        }
        maxN += '9';
    }
    for (int i = 0; i < m; ++i) {
        if (i == 0) {
            minM += '1';
        } else {
            minM += '0';
        }
        maxM += '9';
    }
    int minNn = stoi(minN), maxNn = stoi(maxN), minMm = stoi(minM), maxMm = stoi(maxM);
    vector<int> ans;
    ans.push_back(abs(minNn - minMm));
    ans.push_back(abs(maxNn - minMm));
    ans.push_back(abs(minNn - maxMm));
    ans.push_back(abs(maxNn - maxMm));
    sort(ans.begin(), ans.end());
    cout << ans[0] << " " <<ans[ans.size()-1];
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