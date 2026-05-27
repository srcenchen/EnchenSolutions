#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int t; cin >> t;
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> heapSmall;
    priority_queue<int, vector<int>, less<int>> heapBig; // 第k小
    auto push = [&](int x) {
        if (heapBig.size() == 0) {
            heapBig.push(x);
            return ;
        }
        if (x > heapBig.top()) {
            heapSmall.push(x);
        } else {
            heapBig.push(x);
        }
        if (heapBig.size() > heapSmall.size() + 1) {
            heapSmall.push(heapBig.top());
            heapBig.pop();
        }
        if (heapSmall.size() > heapBig.size()) {
            heapBig.push(heapSmall.top());
            heapSmall.pop();
        }
    };
    push(t);
    while (q--) {
        int a, b;
        cin >> a >> b;
        push(a); push(b);
        cout << heapBig.top() << endl;
        
    }
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