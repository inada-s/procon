#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

int N;
void dfs(string& s, char mx) {
    if (s.size() == N) {
        cout << s << endl;
        return;
    }
    for (char c = 'a'; c <= mx; c++) {
        s.push_back(c);
        dfs(s, (c == mx) ? (mx + 1) : mx);
        s.pop_back();
    }
}

void solve(long long N_) {
    N = N_;
    string s = "";
    dfs(s, 'a');
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
