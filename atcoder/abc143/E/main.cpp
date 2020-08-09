#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long M, long long L, std::vector<long long> A,
           std::vector<long long> B, std::vector<long long> C, long long Q,
           std::vector<long long> s, std::vector<long long> t) {}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    long long L;
    scanf("%lld", &L);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    std::vector<long long> C(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
        scanf("%lld", &C[i]);
    }
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> s(Q);
    std::vector<long long> t(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &s[i]);
        scanf("%lld", &t[i]);
    }
    solve(N, M, L, std::move(A), std::move(B), std::move(C), Q, std::move(s),
          std::move(t));
    return 0;
}
