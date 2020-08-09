#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl


vector<long long> a, b, c;

long long memo[1010][1 << 13];
long long dfs(int i, int rem) {
    if (rem == 0) return 0;
    if (i == a.size()) {
        if (rem) return 1LL << 32;
        return 0;
    }
    if (memo[i][rem] != -1) return memo[i][rem];
    return memo[i][rem] = min(dfs(i + 1, rem), dfs(i + 1, rem & ~c[i]) + a[i]);
}

int main() {
    memset(memo, -1, sizeof(memo));
    int N, M;
    cin >> N >> M;
    a.resize(M);
    b.resize(M);
    c.resize(M);
    rep (i, M) {
        cin >> a[i] >> b[i];
        c[i] = 0;
        rep (j, b[i]) {
            int t;
            cin >> t;
            t--;
            c[i] |= (1 << t);
        }
    }
    auto ans = dfs(0, (1 << N) - 1);
    if ((1LL << 32) <= ans ) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
