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


void solve(long long N, long long M, std::vector<long long> C, std::vector<long long> A, std::vector<std::vector<long long>> L) {

}

int main() {
    long long N;
    std::scanf("%lld", &N);
    long long M;
    std::scanf("%lld", &M);
    std::vector<long long> C(N);
    for(int i = 0 ; i < N ; i++){
        std::scanf("%lld", &C[i]);
    }
    std::vector<long long> A(M);
    for(int i = 0 ; i < M ; i++){
        std::scanf("%lld", &A[i]);
    }
    std::vector<std::vector<long long>> L(M, std::vector<long long>(N));
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            std::scanf("%lld", &L[i][j]);
        }
    }
    solve(N, M, std::move(C), std::move(A), std::move(L));
    return 0;
}
