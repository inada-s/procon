#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const long long MOD = 1000000007;

void solve(long long N, long long K, std::vector<long long> A,
           std::vector<long long> B) {}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(K);
    std::vector<long long> B(K);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(N, K, std::move(A), std::move(B));
    return 0;
}
