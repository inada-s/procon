#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long M, std::vector<long long> x,
           std::vector<long long> y) {}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    std::vector<long long> x(M);
    std::vector<long long> y(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &x[i]);
        scanf("%lld", &y[i]);
    }
    solve(N, M, std::move(x), std::move(y));
    return 0;
}
