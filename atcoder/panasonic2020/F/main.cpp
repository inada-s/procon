#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long Q, std::vector<long long> a, std::vector<long long> b,
           std::vector<long long> c, std::vector<long long> d) {}

int main() {
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> a(Q);
    std::vector<long long> b(Q);
    std::vector<long long> c(Q);
    std::vector<long long> d(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
        scanf("%lld", &c[i]);
        scanf("%lld", &d[i]);
    }
    solve(Q, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}
