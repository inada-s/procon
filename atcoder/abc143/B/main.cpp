#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, std::vector<long long> d) {
    long long ans = 0;
    rep (i, N) {
        loop (j, i+1, N) {
            ans += d[i] * d[j];
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> d(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &d[i]);
    }
    solve(N, std::move(d));
    return 0;
}
