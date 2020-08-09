#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long A, long long B, long long H, long long M) {
    double ta = 4 * acos(0) * (H/12.0 + M/720.0);
    double tb = 4 * acos(0) * M / 60.0;
    double ax = A * sin(ta);
    double ay = A * cos(ta);
    double bx = B * sin(tb);
    double by = B * cos(tb);
    double ans = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    printf("%.20f\n", ans);
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long H;
    scanf("%lld", &H);
    long long M;
    scanf("%lld", &M);
    solve(A, B, H, M);
    return 0;
}
