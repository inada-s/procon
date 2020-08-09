#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N, long long M, std::string S, std::string T) {
    long long O = max(N, M);
    if (S == T) {
        cout << N << endl;
    }
    if (S[0] == T[0]) {
        cout << -1 << endl;
    }
    loop (k, 1, 1000000) {
        O * k
    }
 }

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(N, M, S, T);
    return 0;
}
