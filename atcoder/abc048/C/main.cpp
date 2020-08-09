#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long x, std::vector<long long> a) {
    long long ans1 = 0;
    auto cp = a;
    loop (i, 1, N) {
        if (a[i-1] + a[i] > x) {
            auto d = a[i-1] + a[i] - x;
            a[i] -= d;
            ans1 += d;
            if (a[i] < 0) a[i] = 0;
        }
    }

    long long ans2 = 0;
    a = cp;
    reverse(a.begin(), a.end());
    loop (i, 1, N) {
        if (a[i-1] + a[i] > x) {
            auto d = a[i-1] + a[i] - x;
            a[i] -= d;
            ans2 += d;
            if (a[i] < 0) a[i] = 0;
        }
    }

    cout << min(ans1, ans2) << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long x;
    scanf("%lld", &x);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, x, std::move(a));
    return 0;
}
