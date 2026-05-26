const int MOD = 998244353;
const int MAXN = 200005;
const int MAXD = 1000005;

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

// 计算排列数 A(n, k)
long long nPr(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    
    long long num = 1;
    for (long long i = 0; i < k; i++) {
        // 注意 n 可能是巨大的，每次相乘前先取模
        num = (num * ((n - i) % MOD)) % MOD;
    }
    return num % MOD;
}