#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto t = s;
    sort(t.begin(), t.end());

    int l = 0;
    int r = n-1;
    int ans = 0;
    for (;;) {

        for (; l < n; l++) {
            if (s[l] != t[l]) {
                break;
            }
        }

        for (; 0 <= r; r--) {
            if (s[r] != t[r]) {
                break;
            }
        }

        if (l <= r) {
            ans++;
            l++;
            r--;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
