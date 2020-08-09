#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N) {
    vector<int> ps;
    loop (k, 2, 1000001) {
        auto cnt = 0;
        while (N % k == 0) {
            N /= k;
            cnt++;
        }
        if (cnt) {
            ps.push_back(cnt);
        }
    }
    if (N != 1) {
        ps.push_back(1);
    }

    int ans = 0;
    rep (i, ps.size()) {
        int a = ps[i];
        loop (t, 1, ps[i]+1) {
            if (t <= a) {
                a -= t;
                ans++;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;

}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
