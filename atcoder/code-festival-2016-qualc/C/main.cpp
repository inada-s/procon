#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> T, std::vector<long long> A) {}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> T(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &T[i]);
    }
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(T), std::move(A));
    return 0;
}
