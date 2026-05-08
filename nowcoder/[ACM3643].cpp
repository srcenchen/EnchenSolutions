#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int pop(deque<int>& deq, bool tog) {
    int r;
    if (tog) { // 翻转 右侧出
        r = deq.back();
        deq.pop_back();
        return r;
    }
    r = deq.front();
    deq.pop_front();
    return r;
}
void push(deque<int>& deq, bool tog, int val) {
    if (tog) { // 翻转模式，左侧进
        deq.push_front(val);
    } else {
        deq.push_back(val);
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        nums[i] = i;
    }
    deque<int> deq; // 双端队列
    bool tog = false; // 标记位置 0 代表左端 1 代表右端
    int deqConL = INT_MAX, deqConR = 0;
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (a>deqConL) {
            // 弹出多余的
            while (a-deqConL != 0) {
                if (!deq.empty()) 
                    cout << pop(deq, tog) << " ";
                else {
                    cout << deqConL << " ";
                    deqConR = deqConL;
                }
                deqConL++;
            }
        }
        deqConL = a;
        //deqConR = max(deqConR, a);
        // 压入比较小的
        while (deqConR-b < 0) {
            push(deq, tog, nums[++deqConR]);
        }
        tog = !tog;
    }
    // 最后清零
    while (!deq.empty()) {
        cout << pop(deq, tog) << " ";
    }
    // 剩下没有变化的，也弹出
    for (int i = deqConR + 1; i <= n; ++i) {
        cout << i << " ";
    }
}
signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}