#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
using ll = long long;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#ifdef LOCAL
#define dump(a) cerr << #a << " = " << (a) << " (L:" << __LINE__ << ")" << endl
#else
#define dump(a)
#endif


void solve(long long N, long long M, std::vector<long long> A) {
    sort(A.begin(), A.end());
    int ans = 0;
    rep(i, N) {
        ans = max<int>(ans, lower_bound(A.begin(), A.end(), A[i] + M) - lower_bound(A.begin(), A.end(), A[i]));
    }
    cout << ans << endl;
}

int main() {
    long long N;
    std::scanf("%lld", &N);
    long long M;
    std::scanf("%lld", &M);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        std::scanf("%lld", &A[i]);
    }
    solve(N, M, std::move(A));
    return 0;
}
