#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, std::vector<long long> A) {
    sort(A.begin(), A.end());
    int ub = 1000001;
    vector<int> ban(ub);
    vector<int> used(ub);
    int ans = 0;
    rep(i, N) {
        used[A[i]]++;
        if (2 <= used[A[i]]) continue;
        loop (j, 1, 1000001) {
            auto t = A[i] * j;
            if (ub <= t) break;
            ban[t]++;
        }
    }
    rep (i, N) {
        if (ban[A[i]] == 1 && used[A[i]] == 1) ans++;
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
