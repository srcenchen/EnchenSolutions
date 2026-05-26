#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAXN = 200005;
const int MAXD = 1000005;

long long C[MAXN], D[MAXN];
long long pool[MAXN], sumD[MAXN];
vector<int> adj[MAXN];

long long factInv[MAXD];
// 快速幂计算逆元
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 预处理阶乘的逆元
void precompute() {
    long long fact = 1;
    for (int i = 1; i < MAXD; i++) {
        fact = (fact * i) % MOD;
    }
    factInv[MAXD - 1] = power(fact, MOD - 2);
    for (int i = MAXD - 2; i >= 0; i--) {
        factInv[i] = (factInv[i + 1] * (i + 1)) % MOD;
    }
}

// 计算组合数 C(n, k)
long long nCr(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    
    long long num = 1;
    for (long long i = 0; i < k; i++) {
        // 注意 n 可能是巨大的，每次相乘前先取模
        num = (num * ((n - i) % MOD)) % MOD;
    }
    return (num * factInv[k]) % MOD;
}
void solve() {
    int n;
    cin >> n;
    vector<int> cands(n+1, 0), need(n+1);
    vector<vector<int>> edges(n+1);
    for (int i = 2; i <= n; ++i) {
        int t; cin >> t;
        edges[t].push_back(i);
        // edges[i].push_back(t);

    }
    for (int i = 1; i <= n; ++i) {
        cin >> cands[i];
    }
    for (int i = 1; i <=n; ++i) {
        cin >> need[i];
    }
    int ans = 1;
    // 定义：第x个子树 返回当前池子里可用糖果数量
    auto dfs = [&](auto&& dfs, int x) -> int {
        int cur = cands[x];
        for (auto& i : edges[x]) {
            int tmp = dfs(dfs, i);
            if (tmp == -1) {
                return -1;
            }
            cur += tmp;
        }
        if (cur < need[x]) {
            // cout << 0 << endl;
            return -1;
        }
        ans = (ans * nCr(cur, need[x])) % MOD;
        return cur - need[x];
    };
    if (dfs(dfs, 1) == -1) {
        cout << 0 << endl;
        return;
    }
    cout << ans % MOD << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    precompute();
    // cin >> T;
    while(T--) solve();
    return 0;
}