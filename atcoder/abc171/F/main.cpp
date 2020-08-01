#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

const long long MOD = 1000000007;
const int FACT_MAX = 5000000;
long long fact[FACT_MAX];
long long inv[FACT_MAX];
long long invfact[FACT_MAX];
long long nPr(int n, int r) { return (fact[n] * invfact[n - r]) % MOD; }
long long nCr(int n, int r) {
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}
void initialize_fact() {
    fact[0] = 1;
    inv[0] = 0;
    inv[1] = 1;
    invfact[0] = 1;
    loop(i, 1, FACT_MAX) fact[i] = (i * fact[i - 1]) % MOD;
    loop(i, 2, FACT_MAX) inv[i] = MOD - ((MOD / i) * inv[MOD % i] % MOD);
    loop(i, 1, FACT_MAX) invfact[i] = (invfact[i - 1] * inv[i]) % MOD;
}

const int POW_MAX = 5000000;
long long pow25[POW_MAX];
long long pow26[POW_MAX];

void init() {
    pow25[0] = 1;
    pow26[0] = 1;
    loop (i, 1, POW_MAX) {
        pow25[i] = (pow25[i-1] * 25) % MOD;
        pow26[i] = (pow26[i-1] * 26) % MOD;
    }
}

void solve(long long K, std::string S) {
    initialize_fact();
    init();

    long long ans = 0;
    rep(k, K+1) {
        ans = (ans + (((nCr(k+S.size()-1, S.size()-1) * pow25[k]) % MOD) * pow26[K-k]) % MOD) % MOD;
    }
    cout << ans << endl;
}

int main() {
    long long K;
    scanf("%lld", &K);
    std::string S;
    std::cin >> S;
    solve(K, S);
    return 0;
}
