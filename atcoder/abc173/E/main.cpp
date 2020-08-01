#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
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

void solve(long long N, long long K, std::vector<long long> A) {
    sort(A.begin(), A.end(),
         [](long long a, long long b) { return abs(a) < abs(b); });
    reverse(A.begin(), A.end());

    vector<long long> plus, minus;
    rep(i, N) {
        if (0 <= A[i])
            plus.push_back(A[i]);
        else
            minus.push_back(A[i]);
    }

    long long ans = 1;
    int pi = 0, mi = 0;

    if (K % 2 == 1) {
        if (pi < plus.size()) {
            ans = (ans * plus[pi]) % MOD;
            pi++;
        }
    }

    while (pi + mi + 2 <= K) {
        long long a = -1;
        long long b = -1;
        if (pi + 1 < plus.size()) {
            a = plus[pi] * plus[pi + 1];
        }
        if (mi + 1 < minus.size()) {
            b = minus[mi] * minus[mi + 1];
        }

        if (a == -1 && b == -1) {
            break;
        }

        if (a >= b) {
            pi += 2;
            ans = (ans * (a % MOD)) % MOD;
        } else {
            mi += 2;
            ans = (ans * (b % MOD)) % MOD;
        }
    }

    if (pi + mi == K) {
        cout << (ans + MOD) % MOD << endl;
        return;
    }

    sort(A.begin(), A.end(),
         [](long long a, long long b) { return abs(a) < abs(b); });
    ans = 1;
    rep(i, K) { ans = (ans * A[i] + MOD) % MOD; }
    cout << (ans + MOD) % MOD << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}
