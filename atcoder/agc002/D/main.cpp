#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long M, std::vector<long long> a,
           std::vector<long long> b, long long Q, std::vector<long long> x,
           std::vector<long long> y, std::vector<long long> z) {}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> x(Q);
    std::vector<long long> y(Q);
    std::vector<long long> z(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &x[i]);
        scanf("%lld", &y[i]);
        scanf("%lld", &z[i]);
    }
    solve(N, M, std::move(a), std::move(b), Q, std::move(x), std::move(y),
          std::move(z));
    return 0;
}
