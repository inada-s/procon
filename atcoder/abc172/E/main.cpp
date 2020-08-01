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
const int FACT_MAX = 1000000;
long long fact[FACT_MAX];
long long inv[FACT_MAX];
long long invfact[FACT_MAX];
void pre() {
    fact[0] = 1;
    inv[0] = 0;
    inv[1] = 1;
    invfact[0] = 1;
    loop(i, 1, FACT_MAX) fact[i] = (i * fact[i - 1]) % MOD;
    loop(i, 2, FACT_MAX) inv[i] = MOD - ((MOD / i) * inv[MOD % i] % MOD);
    loop(i, 1, FACT_MAX) invfact[i] = (invfact[i - 1] * inv[i]) % MOD;
}

long long nPr(int n, int r) { return (fact[n] * invfact[n - r]) % MOD; }

long long nCr(int n, int r) {
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

void solve(long long N, long long M) {
    pre();
    long long ans = 0;
    rep(i, N + 1) {
        long long a = (nCr(N, i) * nPr(M, i)) % MOD;
        a = (a * nPr(M - i, N - i)) % MOD;
        a = (a * nPr(M - i, N - i)) % MOD;
        if (i % 2 == 0)
            ans = (ans + a) % MOD;
        else
            ans = (ans - a + MOD) % MOD;
    }
    cout << (ans + MOD) % MOD << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    solve(N, M);
    return 0;
}
