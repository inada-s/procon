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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long X, long long Y, std::vector<long long> A) {

}

int main() {
    long long N;
    std::scanf("%lld", &N);
    long long X;
    std::scanf("%lld", &X);
    long long Y;
    std::scanf("%lld", &Y);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        std::scanf("%lld", &A[i]);
    }
    solve(N, X, Y, std::move(A));
    return 0;
}
