#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

map<long long, long long> memo;
long long dfs(long long H) {
    if (H == 1) return 1;
    auto it = memo.find(H);
    if (it != memo.end()) return it->second;
    return memo[H] = 1 + 2 * dfs(H/2);
}

void solve(long long H) {
    cout << dfs(H) << endl;
}

int main() {
    long long H;
    scanf("%lld", &H);
    solve(H);
    return 0;
}
