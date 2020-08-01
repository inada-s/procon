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

const double PI = acos(-1.0);

void solve(long long N, std::vector<long long> u, std::vector<long long> v) {
    long long ans = 0;

    rep(i, N) { 
        ans += (i+1) * (N-i);
    }

    rep(i, N-1) { 
        if (u[i] > v[i]) swap(u[i], v[i]);
        ans -= u[i] * (N - v[i] + 1);
    }

    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> u(N - 1);
    std::vector<long long> v(N - 1);
    for (int i = 0; i < N - 1; i++) {
        scanf("%lld", &u[i]);
        scanf("%lld", &v[i]);
    }
    solve(N, std::move(u), std::move(v));
    return 0;
}
