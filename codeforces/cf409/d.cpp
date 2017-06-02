#include<iostream>
#include<complex>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// http://www.prefield.com/algorithm/geometry/geometry.html
typedef complex<double> P;
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

int main() {
  int n;
  vector<P> g;
  while (cin >> n) {
    g.resize(n);

    for (int i = 0; i < n; ++i) {
      double a, b;
      cin >> a >> b;
      g[i] = P(a, b);
    }

    double ans = 1e100;
    for (int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      int k = (i - 1 + n) % n;

      auto p = g[i];
      auto a = g[j];
      auto b = g[k];

      auto ab = (b - a) / abs(b - a);
      auto x = a + (ab * dot(ab, p - a));
      ans = min(ans, abs(x - p) / 2.0);
    }

    printf("%.10f\n", ans);
  }
}
