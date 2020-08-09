#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const string YES = "Yes";
const string NO = "No";

void solve(long long X) {
    if (30 <= X) cout << YES << endl;
    else cout << NO << endl;
}

int main() {
    long long X;
    scanf("%lld", &X);
    solve(X);
    return 0;
}
