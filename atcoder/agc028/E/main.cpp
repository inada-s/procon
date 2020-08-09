#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, std::vector<long long> P) {}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &P[i]);
    }
    solve(N, std::move(P));
    return 0;
}
