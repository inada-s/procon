#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

void solve(long long N, std::vector<long long> A, long long Q,
           std::vector<long long> B, std::vector<long long> C) {
    map<long long, int> m;
    rep(i, N) m[A[i]]++;
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    rep(i, Q) {
        sum += m[B[i]] * C[i] - m[B[i]] * B[i];
        m[C[i]] += m[B[i]];
        m[B[i]] = 0;
        cout << sum << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> B(Q);
    std::vector<long long> C(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &B[i]);
        scanf("%lld", &C[i]);
    }
    solve(N, std::move(A), Q, std::move(B), std::move(C));
    return 0;
}
