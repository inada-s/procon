#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long K, std::vector<long long> h) {}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> h(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &h[i]);
    }
    solve(N, K, std::move(h));
    return 0;
}
