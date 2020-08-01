#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

bool bit(long long n, int k) { return (n >> k) & 1LL; }


long long a,b,c;
long long dfs(int i, long long x) {
    long long m = 1LL << 62;
    if (a <= x) return m;
    if (i == 41) {
        if ((a - x) ^ (b + x) == c, i) {
            return x;
        } else {
            return m;
        }
    }

    auto y = x;
    if (bit((a - x) ^ (b + x), i) == bit(c, i)) {
        m = min(m, dfs(i + 1, x));
    }
    y = x | (1LL << i);
    if (bit((a - y) ^ (b + y), i) == bit(c, i)) {
        m = min(m, dfs(i + 1, y));
    }
    return m;
}

void solve(long long N, std::vector<long long> A) {
    a = A[0];
    b = A[1];
    c = 0;
    loop(i, 2, N) c ^= A[i];
    long long x = dfs(0, 0);
    if (x < a && (a - x) ^ (b + x) == c) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
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
