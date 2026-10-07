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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());
    int ans = 0;
    rep(i, N) {
        ans = max<int>(ans, lower_bound(A.begin(), A.end(), A[i] + M) - lower_bound(A.begin(), A.end(), A[i]));
    }
    cout << ans << endl;

    return 0;
}
