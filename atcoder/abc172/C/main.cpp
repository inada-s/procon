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

void solve(long long N, long long M, long long K, std::vector<long long> A,
           std::vector<long long> B) {
    vector<long long> X, Y;
    X.push_back(0);
    Y.push_back(0);
    rep(i,N) X.push_back(A[i]);
    rep(i,M) Y.push_back(B[i]);
    loop(i, 1, X.size()) X[i] += X[i-1];
    loop(i, 1, Y.size()) Y[i] += Y[i-1];

    int ans = 0;
    rep(i, X.size()) {
        auto k = K - X[i];
        if (0 <= k) {
            int j = upper_bound(Y.begin(), Y.end(), k) - Y.begin();
            ans = max(ans, i + j - 1);
        }
    }

    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    std::vector<long long> B(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &B[i]);
    }
    solve(N, M, K, std::move(A), std::move(B));
    return 0;
}
