#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

template <typename T>
struct BIT {
    int N;
    vector<T> bit;
    BIT(int N) : N(N), bit(N + 1) {}
    void add(int a, T v) {
        for (int x = a; x <= N; x += x & -x) {
            bit[x] += v;
        }
    }
    T sum(T a) {
        T ret = 0;
        for (int x = a; 0 < x; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
};

template <typename T>
struct SegTree {
    vector<T> dat;

    SegTree(int n) {
        int k = 1;
        while (k < n) k *= 2;
        dat = vector<T>(2 * k - 1, INT_MAX); // TODO
    }

    void update(int k, T a) {
        k += dat.size() - 1;
        dat[k] = a;
        while (0 < k) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // TODO
        }
    }

    T query_(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INT_MAX; // TODO
        if (a <= l || r <= b) return dat[k];
        auto vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        auto vr = query(a, b, k * 2 + 2, (l + r) / 2, r); u
        return min(vl, vr); // TODO
    }

    T query(int a, int b) {
        return query_(a, b, 0, 0, dat.size());
    }
};

void solve(long long N, long long Q, std::vector<long long> c,
           std::vector<long long> l, std::vector<long long> r) {
    vector<pair<pair<int, bool>, int> > pairs;
    map<long long, int> tmp;
    rep(i, N) {
        if (tmp.find(c[i]) != tmp.end())
            pairs.emplace_back(make_pair(tmp[c[i]], true), i);
        tmp[c[i]] = i;
    }
    rep(i, Q) { pairs.emplace_back(make_pair(--l[i], false), --r[i]); }

    sort(pairs.begin(), pairs.end());

    BIT<int> bit(N);
    map<pair<long long, long long>, int> ans_map;
    for (int i = pairs.size() - 1; 0 <= i; i--) {
        auto range = make_pair(pairs[i].first.first, pairs[i].second);
        bool q = !pairs[i].first.second;

        if (q)
            ans_map[range] = bit.sum(range.second);
        else
            bit.add(range.second, 1);
    }

    rep(i, Q) {
        cout << r[i] - l[i] + 1 - ans_map[make_pair(l[i], r[i])] << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> c(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &c[i]);
    }
    std::vector<long long> l(Q);
    std::vector<long long> r(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &l[i]);
        scanf("%lld", &r[i]);
    }
    solve(N, Q, std::move(c), std::move(l), std::move(r));
    return 0;
}
