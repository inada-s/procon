#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const string YES = "Possible";
const string NO = "Impossible";

void solve(long long N, long long L, std::vector<long long> a) {
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    int i = 0, j = N - 2;
    vector<int> ans;
    while (i != j) {
        int x = a[i] + a[i + 1];
        int y = a[j] + a[j + 1];
        if (sum < L) {
            cout << NO << endl;
            return;
        }
        if (x < y) {
            ans.push_back(i);
            sum -= a[i];
            i++;
        } else {
            ans.push_back(j);
            sum -= a[j + 1];
            j--;
        }
    }
    if (a[i] + a[i + 1] < L) {
        cout << NO << endl;
        return;
    }
    ans.push_back(i);

    cout << YES << endl;
    rep(i, ans.size()) { cout << ans[i] + 1 << endl; }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long L;
    scanf("%lld", &L);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, L, std::move(a));
    return 0;
}
