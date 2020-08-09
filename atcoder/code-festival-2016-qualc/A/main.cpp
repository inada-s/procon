#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const string YES = "Yes";
const string NO = "No";

void solve(std::string S) {
    bool f = false;
    rep (i, S.size()) {
        if (S[i] == 'C') f = true;
        if (f && S[i] == 'F') {
            cout << YES << endl;
            return;
        }
    }
    cout << NO << endl;
}

int main() {
    std::string s;
    std::cin >> s;
    solve(s);
    return 0;
}
