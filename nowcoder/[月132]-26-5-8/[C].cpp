#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<long long> all_nums;

void prepare() {
    for (int i = 0; i < 63; ++i) {
        for (int j = i; j < 63; ++j) {
            __int128 cur = (1LL << i) +(1LL << j);
            if (cur < (1LL << 62)) {
                all_nums.push_back(cur);
            }
        }
    }
    sort(all_nums.begin(), all_nums.end());
    // for (auto& i : all_nums) {
    //     cout << i << endl;
    // }
}
void solve() {

    int a, b;
    cin >> a >>b;
    auto L = lower_bound(all_nums.begin(), all_nums.end(), a);
    auto R = upper_bound(all_nums.begin(), all_nums.end(), b);
    cout << R - L;
}
signed main() {
    ios::sync_with_stdio(false);
    prepare();
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}