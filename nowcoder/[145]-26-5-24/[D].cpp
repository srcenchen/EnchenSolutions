#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> cnt;
    unordered_set<int> b, c;
    int cntA = 0, cntB = 0;
    int tar = n/2;
    vector<int> ansB(n, -1), ansC(n, -1);
    for (int i = 0; i < n; ++i)  {
        cin >> nums[i];
        cnt[nums[i]]++;
        if (cnt[nums[i]] >= 3) {
            cout << -1; // 禁止重复三次！
            return;
        }
        if (cnt[nums[i]] == 2) tar--;
    }

    for (int i = 0; i < n; ++i) {
        // 次数为2的特判
        if (cnt[nums[i]] == 2) {
            if (b.count(nums[i])) {
                c.insert(nums[i]);
                ansC[i] = nums[i];
            } else {
                b.insert(nums[i]);
                ansB[i] = nums[i];
            }
            continue;
        }
        if (cntA < tar) {
            b.insert(nums[i]);
            ansB[i] = nums[i];
            cntA++;
        } else {
            c.insert(nums[i]);
            ansC[i] = nums[i];
            cntB++;
        }
    }
    if (cntA < tar || cntB < tar) {
        cout << -1;
        return;
    }
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        if (ansB[i] != -1) continue;
        while (b.count(cur)) {
            cur++;
        }
        ansB[i] = cur++;
    }
    cur = 1;
    for (int i = 0; i < n; ++i) {
        if (ansC[i] != -1) continue;
        while (c.count(cur)) {
            cur++;
        }
        ansC[i] = cur++;
    }
    for (auto& i : ansB) {
        cout << i << " ";
    }
    cout << endl;
    for (auto& i : ansC) {
        cout << i << " ";
    }
    cout << endl;

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