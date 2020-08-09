#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long D, std::vector<long long> X,
           std::vector<long long> Y) {
    int cnt = 0;
    rep(i, N) {
        if (X[i] * X[i] + Y[i] * Y[i] <= D * D) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long D;
    scanf("%lld", &D);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &X[i]);
        scanf("%lld", &Y[i]);
    }
    solve(N, D, std::move(X), std::move(Y));
    return 0;
}
