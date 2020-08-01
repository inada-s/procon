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

void solve(long long N, std::vector<long long> X, std::vector<long long> Y,
           std::vector<long long> P) {}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    std::vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &X[i]);
        scanf("%lld", &Y[i]);
        scanf("%lld", &P[i]);
    }
    solve(N, std::move(X), std::move(Y), std::move(P));
    return 0;
}
