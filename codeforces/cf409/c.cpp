#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  int n, p;
  while (cin >> n >> p) {
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }

    long long s = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
    }

    if (s <= p) {
      cout << -1 << endl;
      continue;
    }

    double ub = 1e100;
    double lb = 0;

    for (int ite = 0; ite < 1000; ++ite) {
      double t = (ub - lb) / 2.0 + lb;
      double E = 0;
      for (int i = 0; i < n; ++i) {
        double e = b[i] - t * a[i];
        if (e < 0) {
          E += -e;
        }
      }

      if (p * t < E) {
        ub = t;
      } else {
        lb = t;
      }
    }
    cout << ub << endl;
  }
}
