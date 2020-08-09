#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long K, std::string S) {
    if (S.size() <= K) {
        cout << S << endl;
        return;
    }
    cout << S.substr(0, K) << "..." << endl;
}

int main() {
    long long K;
    scanf("%lld", &K);
    std::string S;
    std::cin >> S;
    solve(K, S);
    return 0;
}
