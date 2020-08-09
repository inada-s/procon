#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const long long MOD = 998244353;

void solve(long long N, long long S, std::vector<long long> A) {
    vector<vector<long long> > dp(4000, vector<long long>(4000, 0));
    dp[0][0] = 1;
    rep (i, N) {
        rep (j, S+1) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            if (j + A[i] <= S) {
                dp[i+1][j + A[i]] += dp[i][j];
                dp[i+1][j + A[i]] %= MOD;
            }
        }
    }
    cout << dp[N][S] << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long S;
    scanf("%lld", &S);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, S, std::move(A));
    return 0;
}
