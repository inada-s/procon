#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long K) {
    long long s = 7;
    rep (i, K) {
        if (s % K == 0) {
            cout << i + 1 << endl;
            return;
        }
        s = s * 10 + 7;
        s %= K;
    }
    cout << -1 << endl;
}

int main() {
    long long K;
    scanf("%lld", &K);
    solve(K);
    return 0;
}
