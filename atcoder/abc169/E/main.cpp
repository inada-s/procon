#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, std::vector<long long> A, std::vector<long long> B) {
    vector<long long> as, bs;
    rep (i, N) {
        as.emplace_back(A[i]);
        bs.emplace_back(B[i]);
    }

    sort(as.begin(), as.end());
    sort(bs.rbegin(), bs.rend());

    if (N % 2 == 1) {
        long long med1 = as[N/2];
        long long med2 = bs[N/2];
        cout << med2 - med1 + 1 << endl;
    }
    else {
        long long med1 = (as[N/2] + as[N/2-1]);
        long long med2 = (bs[N/2] + bs[N/2-1]);
        cout << med2 - med1 + 1 << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(N, std::move(A), std::move(B));
    return 0;
}
