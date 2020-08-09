#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long K, long long T, std::vector<long long> a) {}

int main() {
    long long K;
    scanf("%lld", &K);
    long long T;
    scanf("%lld", &T);
    std::vector<long long> a(T);
    for (int i = 0; i < T; i++) {
        scanf("%lld", &a[i]);
    }
    solve(K, T, std::move(a));
    return 0;
}
