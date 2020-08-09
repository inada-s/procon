#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

template <typename T>
T compress4(vector<T>& x1, vector<T>& x2, vector<T>& x3, vector<T>& x4) {
    set<T> xss;
    for (auto& x : x1) xss.emplace(x), xss.emplace(x + 1);
    for (auto& x : x2) xss.emplace(x), xss.emplace(x + 1);
    for (auto& x : x3) xss.emplace(x), xss.emplace(x + 1);
    for (auto& x : x4) xss.emplace(x), xss.emplace(x + 1);
    vector<T> xs(xss.begin(), xss.end());
    for (auto& x : x1) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    for (auto& x : x2) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    for (auto& x : x3) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    for (auto& x : x4) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    return xs.size();
}
/*
// abc168
for (auto& x : a) x *= 2;
for (auto& x : b) x *= 2;
for (auto& x : c) x *= 2;
for (auto& x : d) x *= 2;
for (auto& x : e) x *= 2;
for (auto& x : f) x *= 2;
vector<long long> ox = {0};
vector<long long> oy = {0};
long long W = compress4(ox, a, b, d);
long long H = compress4(oy, c, e, f);
vector<long long> rx(W + 1);
vector<long long> ry(H + 1);
rx[ox[0]] = 0;
ry[oy[0]] = 0;
rep(i, N) {
    rx[a[i]] = A[i];
    rx[b[i]] = B[i];
    ry[c[i]] = C[i];
}
rep(i, M) {
    rx[d[i]] = D[i];
    ry[e[i]] = E[i];
    ry[f[i]] = F[i];
}
*/

void solve(long long N, long long M, std::vector<long long> A,
           std::vector<long long> B, std::vector<long long> C,
           std::vector<long long> D, std::vector<long long> E,
           std::vector<long long> F) {
    auto a = A;
    auto b = B;
    auto c = C;
    auto d = D;
    auto e = E;
    auto f = F;
    for (auto& x : a) x *= 2;
    for (auto& x : b) x *= 2;
    for (auto& x : c) x *= 2;
    for (auto& x : d) x *= 2;
    for (auto& x : e) x *= 2;
    for (auto& x : f) x *= 2;
    vector<long long> ox = {0};
    vector<long long> oy = {0};
    long long W = compress4(ox, a, b, d);
    long long H = compress4(oy, c, e, f);
    vector<long long> rx(W + 1);
    vector<long long> ry(H + 1);
    rx[ox[0]] = 0;
    ry[oy[0]] = 0;
    rep(i, N) {
        rx[a[i]] = A[i];
        rx[b[i]] = B[i];
        ry[c[i]] = C[i];
    }
    rep(i, M) {
        rx[d[i]] = D[i];
        ry[e[i]] = E[i];
        ry[f[i]] = F[i];
    }

    vector<vector<bool>> field(W, vector<bool>(H));
    rep(i, N) {
        const auto l = min(a[i], b[i]);
        const auto r = max(a[i], b[i]) + 1;
        loop(x, l, r) field[x][c[i]] = 1;
    }

    rep(i, M) {
        const auto l = min(e[i], f[i]);
        const auto r = max(e[i], f[i]) + 1;
        loop(y, l, r) field[d[i]][y] = 1;
    }

    long long ans = 0;
    stack<uint64_t> Q;
    vector<vector<bool>> visit(W, vector<bool>(H));
    Q.emplace(ox[0] << 32 | oy[0]);
    visit[ox[0]][oy[0]] = 1;
    while (!Q.empty()) {
        uint64_t p = Q.top();
        Q.pop();
        loop(dx, -1, 2) loop(dy, -1, 2) {
            if (dx == 0 && dy == 0) continue;
            const auto nx = (p >> 32) + dx;
            const auto ny = (p & ((1ULL << 32) - 1)) + dy;
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                if (!field[nx][ny] && !visit[nx][ny]) {
                    visit[nx][ny] = 1;
                    ans +=
                        (rx[nx + 1] - rx[nx - 1]) * (ry[ny + 1] - ry[ny - 1]);
                    Q.emplace(nx << 32 | ny);
                }
            } else {
                cout << "INF" << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    std::vector<long long> C(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
        scanf("%lld", &C[i]);
    }
    std::vector<long long> D(M);
    std::vector<long long> E(M);
    std::vector<long long> F(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &D[i]);
        scanf("%lld", &E[i]);
        scanf("%lld", &F[i]);
    }
    solve(N, M, std::move(A), std::move(B), std::move(C), std::move(D),
          std::move(E), std::move(F));
    return 0;
}
