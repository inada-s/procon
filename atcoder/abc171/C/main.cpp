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

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

void solve(long long N) {
    N--;
    string s;
    do {
        s += 'a' + char(N % 26);
        N /= 26;
        N--;
    } while (0 <= N);
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
