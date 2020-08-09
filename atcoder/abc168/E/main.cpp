#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A, std::vector<long long> B) {
    vector<long long> mod_pow2(200001);
    mod_pow2[0] = 1;
    loop(i, 1, 200001) {
        mod_pow2[i] = mod_pow2[i - 1] * 2;
        mod_pow2[i] %= MOD;
    }

    int zeros = 0;
    map<pair<long long, long long>, pair<int, int>> groups;
    rep(i, N) {
        if (A[i] == 0 && B[i] == 0) {
            zeros++;
        } else {
            auto g = __gcd(abs(A[i]), abs(B[i]));
            auto a = A[i] / g;
            auto b = B[i] / g;
            int rot = 0;
            while (!(0 <= a && 0 < b)) {
                swap(a, b);
                b *= -1;
                rot++;
            }
            if (rot % 2 == 0) groups[make_pair(a, b)].first++;
            if (rot % 2 == 1) groups[make_pair(a, b)].second++;
        }
    }

    long long ans = 1;
    for (auto& g : groups) {
        auto a = g.second.first;
        auto b = g.second.second;
        // cerr << "(" << g.first.first << "," << g.first.second << ")";
        // cerr << a << " " << b << endl;
        ans *= 1 + mod_pow2[a] - 1 + mod_pow2[b] - 1;
        ans %= MOD;
    }
    ans += zeros - 1;
    cout << (ans + MOD) % MOD << endl;
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
