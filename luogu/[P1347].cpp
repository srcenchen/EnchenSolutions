#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> point(n);
    vector<vector<int>> g(n);
    vector<int> inG(n);
    unordered_set<int> se;
    auto run = [&](bool& unique)->string {
        // 执行拓扑排序
        vector<int> inGT = inG;
        queue<int> que;
        for (int i = 0; i < inGT.size(); ++i) {
            if (inGT[i] == 0 && se.count(i)) {
                que.push(i);
            }
        }
        string str;

        while (!que.empty()) {
            int top = que.front();
            if (que.size() > 1) {
                unique = false;
            }
            que.pop();
            str += 'A' + top;
            for (int i = 0; i < g[top].size(); ++i) {
                if (--inGT[g[top][i]] == 0 && se.count(g[top][i])) {
                    que.push(g[top][i]);
                }
            }
        }
        // cout << str << endl;
        return str;
    };
    for (int i = 0; i < m; ++i) {
        string str;
        cin >> str;
        int a = str[0] - 'A';
        int b = str[2] - 'A';
        se.insert(a);
        se.insert(b);
        g[a].push_back(b);
        inG[b]++;
        bool uni = true;
        string ans = run(uni);
        if (ans.size() != se.size()) {
            // cout << run();
            printf("Inconsistency found after %lld relations.", i+1);
            return;
        } else if (ans.size() == n && uni){
            cout << "Sorted sequence determined after " << i+1 << " relations: " << ans << ".";
            return;
        }
    }
    cout << "Sorted sequence cannot be determined.";
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