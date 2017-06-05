#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,n) for(int i=0; i<n; ++i)
#define ALL(v) begin(v), end(v)
#define DUMP(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl
const double PI = acos(-1.0);

class UnionFind {
  public:
  UnionFind(int n) : p(n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
  
  int root(int x) {
    if (p[x] == x) {
      return x;
    } else {
      return p[x] = root(p[x]);
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    p[x] = y;
  }

  private:
  vector<int> p;
};

int main() {
  std::ios::sync_with_stdio(false);

  int n, q;
  while(cin >> n >> q) {
    UnionFind uf(n);

    int p, a, b;
    while(cin >> p >> a >> b) {
      if (p == 0) {
        uf.unite(a, b);
      } else {
        if (uf.same(a, b)) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
  }
  return 0;
}
