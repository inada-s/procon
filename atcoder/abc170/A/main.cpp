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

void solve(std::vector<long long> x) {
    rep(i, x.size()) {
        if (x[i] == 0) cout << i + 1 << endl;
    }
}

int main() {
    std::vector<long long> x(5);
    for (int i = 0; i < 5; i++) {
        scanf("%lld", &x[i]);
    }
    solve(std::move(x));
    return 0;
}
