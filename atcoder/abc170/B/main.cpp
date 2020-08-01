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

const string YES = "Yes";
const string NO = "No";

void solve(long long X, long long Y) {
    rep (i, 100) rep (j, 100) {
        if (X == i + j && i * 2 + j * 4 == Y) {
            cout << YES << endl;
            return;
        }
    }
    cout << NO << endl;
}

int main() {
    long long X;
    scanf("%lld", &X);
    long long Y;
    scanf("%lld", &Y);
    solve(X, Y);
    return 0;
}
