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

#define loop(i, a, b) for (long long i = (a); i < (b); ++i)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

void solve(long long N) {
    vector<long long> f(10000001, 2);
    f[0] = 0;
    f[1] = 1;
    loop(i, 2, 10000001) {
        loop(j, 2, 10000001) {
            if (i * j < 10000001) f[i * j] += 1;
            else break;
        }
    }
    long long ans = 0;
    loop(i, 1, N+1) {
        ans += i * f[i];
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
