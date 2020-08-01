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
#include <unordered_map>
#include <vector>

using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl


void solve(long long N, std::vector<long long> A) {
    long long money = 1000;
    long long stock = 0;

    rep(i, N) {
        if (i == N-1) {
            money += stock * A[i];
            stock = 0;
            break;
        }
        if (A[i] < A[i+1]) {
            stock += money / A[i];
            money %= A[i];
        }
        if (A[i] > A[i+1]) {
            money += stock * A[i];
            stock = 0;
        }
    }

    cout << money << endl;
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
