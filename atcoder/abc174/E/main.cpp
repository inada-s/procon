#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

long long N; long long K; std::vector<long long> A;
bool ok(long long x) {
    int k = 0;
    rep (i, N) {
        if (x == 0) k += A[i] + 1;
        else k += A[i] / x - (A[i] % x == 0);
    }
    return k <= K;
}

void solve(long long N_, long long K_, std::vector<long long> A_) {
    N = N_;
    K = K_;
    A = A_;

    long long ub = 1LL << 60;
    long long lb = 1;
    long long ans = 1LL << 60;
    while (lb <= ub) {
        long long md = (ub - lb) / 2 + lb;
        if (ok(md)) {
            ub = md;
            ub--;
            ans = min(ans, md);
        } else {
            lb = md;
            lb++;
        }
    }
    cout << ans << endl;
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
