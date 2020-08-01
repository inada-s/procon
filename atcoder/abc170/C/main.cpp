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

void solve(long long X, long long N, std::vector<long long> p) {
    set<long long> s;
    for (auto e : p)s.insert(e);

    int ans = 1 << 30;
    loop (k, -500, 500) {
        if (s.find(k) == s.end() && abs(X-k) < abs(X-ans)) {
            ans = k;
        }
    }
    cout << ans << endl;
}

int main() {
    long long X;
    scanf("%lld", &X);
    long long N;
    scanf("%lld", &N);
    std::vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }
    solve(X, N, std::move(p));
    return 0;
}
