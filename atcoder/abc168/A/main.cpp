#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long N) {
    switch (N%10) {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
        cout << "hon" << endl;
        break;
        case 0:
        case 1:
        case 6:
        case 8:
        cout << "pon" << endl;
        break;
        case 3:
        cout << "bon" << endl;
        break;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
