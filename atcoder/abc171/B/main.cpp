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
#include <numeric>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

void solve(long long N, long long K, std::vector<long long> p) {
    sort(p.begin(), p.end());
    cout << accumulate(p.begin(), p.begin() + K, 0) << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }
    solve(N, K, std::move(p));
    return 0;
}
