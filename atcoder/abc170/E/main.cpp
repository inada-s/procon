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

void solve(long long N, long long Q, std::vector<long long> A,
           std::vector<long long> B, std::vector<long long> C,
           std::vector<long long> D) {
    vector<multiset<long long> > school(200000);
    vector<int> c2s(N);

    rep(i, N) {
        school[B[i]].insert(A[i]);
        c2s[i] = B[i];
    }

    multiset<long long> scores;
    rep(i, school.size()) {
        if (!school[i].empty()) {
            scores.insert(*school[i].rbegin());
        }
    }

    rep(i, Q) {
        auto& prev_school = school[c2s[C[i]]];
        auto& next_school = school[D[i]];
        int rate = A[C[i]];
        prev_school.erase(prev_school.lower_bound(rate));

        if (prev_school.empty()) {
            scores.erase(scores.lower_bound(rate));
        } else if (*prev_school.rbegin() < rate) {
            scores.erase(scores.lower_bound(rate));
            scores.insert(*prev_school.rbegin());
        }

        if (next_school.empty()) {
            scores.insert(rate);
        } else if (*next_school.rbegin() < rate) {
            scores.erase(scores.lower_bound(*next_school.rbegin()));
            scores.insert(rate);
        }

        next_school.insert(rate);
        c2s[C[i]] = D[i];
        cout << *scores.begin() << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
        B[i]--;
    }
    std::vector<long long> C(Q);
    std::vector<long long> D(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &C[i]);
        scanf("%lld", &D[i]);
        C[i]--;
        D[i]--;
    }
    solve(N, Q, std::move(A), std::move(B), std::move(C), std::move(D));
    return 0;
}
