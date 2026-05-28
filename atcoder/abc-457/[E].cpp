#include <bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"
// 待学习
auto cmpL = [](const array<int, 3>& a, const array<int, 3>& b) {
        if (a[0] == b[0]) return a[1] > b[1]; // L 相同，R 降序 (越向右越好)
        return a[0] < b[0]; // L 升序
    };

auto cmpR = [](const array<int, 3>& a, const array<int, 3>& b) {
    if (a[1] == b[1]) return a[0] < b[0]; // R 相同，L 升序 (越向左越好)
    return a[1] < b[1]; // R 升序
};
const int INF = 1e18; // 配合你的 long long

// 定义 DP 的状态节点，存放第一小和第二小的 R 及它们的 id
struct State {
    int r1 = INF, id1 = -1;
    int r2 = INF, id2 = -1;
};

// 核心状态转移逻辑：多路求极小值，更新 top 2
auto updateState = [](State& s, int r, int id) {
    if (r < s.r1) {
        s.r2 = s.r1; s.id2 = s.id1; // 原来的老大退居二线
        s.r1 = r;    s.id1 = id;    // 新老大上位
    } else if (r < s.r2) {
        s.r2 = r;    s.id2 = id;    // 争夺老二的位置
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> L, R, Normal;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        L.push_back({a, b, i});
        R.push_back({a, b, i});
    }
    sort(L.begin(), L.end(), cmpL);
    sort(R.begin(), R.end(), cmpR);
    vector<vector<pair<int, int>>> by_L(n + 2);
    for (int i = 0; i < m; ++i) {
        // L 原数组里存放的是 {l, r, id}
        by_L[ L[i][0] ].push_back({L[i][1], L[i][2]}); 
    }

    // 2. 初始化 DP 数组
    vector<State> dp(n + 2);

    // 3. 从右往左逆推 (自底向上 DP)
    for (int i = n; i >= 1; --i) {
        // 继承右边 (L >= i + 1) 的历史最优解
        dp[i] = dp[i + 1]; 
        
        // 加上当前层 (L == i) 的所有布，重新打榜选出 Top 2
        for (auto& cloth : by_L[i]) {
            int r = cloth.first;
            int id = cloth.second;
            updateState(dp[i], r, id);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        array<int, 3> target = {l, r, 0};
        int lPos = lower_bound(L.begin(), L.end(), target, cmpL) - L.begin();
        int rPos = lower_bound(R.begin(), R.end(), target , cmpR) - R.begin();
        if (lPos == m || rPos == m || L[lPos][0] != l || R[rPos][1] != r) {
            cout << "No" << endl;
            continue;
        }
        int lId = L[lPos][2], rId = R[rPos][2];
        if (lId == rId) {
            // 降级到场景2
            // 现在要在 L >= l 的所有布里，找一个 R 最小的“挂件布”
            int min_r;
            
            // 如果历史记录里最好的那块布，偏偏就是布 A 本身，那就只能用备胎（次优解）
            if (dp[l].id1 == lId) {
                min_r = dp[l].r2;
            } else {
                // 否则直接用历史记录里最好的
                min_r = dp[l].r1;
            }

            // 判断这个挂件布的右端点是否在区间内部
            if (min_r <= r) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
            continue;
        }
        auto [l1, r1, _] = L[lPos];
        auto [l2, r2, _2] = R[rPos];
        if (r1 >= l2 - 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl; 
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}