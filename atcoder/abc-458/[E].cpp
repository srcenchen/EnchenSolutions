#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MOD = 998244353;
const int MAXD = 2e6+7;
long long factInv[MAXD];
long long fact[MAXD];
// 快速幂计算逆元
int qpow(int n, int k) { // n的k次方
    int res = 1;
    n %= MOD;
    while (k) {
        if (k&1) {
            res *= n;
            res %= MOD;
        }
        n *= n;
        n %= MOD;
        k >>= 1;
    }
    return res;
}
// 预处理阶乘的逆元
void precompute() {
    long long factT = 1;
    for (int i = 1; i < MAXD; i++) {
        factT = (factT * i) % MOD;
        fact[i] = factT;
    }
    factInv[MAXD - 1] = qpow(factT, MOD - 2);
    for (int i = MAXD - 2; i >= 0; i--) {
        factInv[i] = (factInv[i + 1] * (i + 1)) % MOD;
    }
}

// 计算组合数 C(n, k)
long long nCr(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    
    long long num = fact[n] * factInv[n-k] % MOD;
    return (num * factInv[k]) % MOD;
}

// 计算排列数 A(n, k)
long long nPr(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    
    long long num = fact[n] * factInv[n-k] % MOD;
    return num % MOD;
}
// 容斥原理
void solve() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int ans = 0;
    for (int i = 0; i <= min(x1, x3); ++i) {
        int tc = nCr(x2+1, i)% MOD * nCr(x1 - i + x2, x2)% MOD * nCr(x3 - i + x2, x2) % MOD;
        if (i&1) ans -= tc;
        else ans += tc;
        ans = (ans + MOD) % MOD;
    }
    cout << ans % MOD;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}