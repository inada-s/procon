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

void solve(long long X) {
    if (400 <= X && X <= 599) cout << "8";
    if (600 <= X && X <= 799) cout << "7";
    if (800 <= X && X <= 999) cout << "6";
    if (1000 <= X && X <= 1199) cout << "5";
    if (1200 <= X && X <= 1399) cout << "4";
    if (1400 <= X && X <= 1599) cout << "3";
    if (1600 <= X && X <= 1799) cout << "2";
    if (1800 <= X && X <= 1999) cout << "1";
    cout << endl;
}

int main() {
    long long X;
    scanf("%lld", &X);
    solve(X);
    return 0;
}
