#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);

  int n, m, k;
  while(cin >> n >> m >> k) {
    vector<int> h(n), u(k), v(k);

    for(int i = 0; i < m; ++i) {
      int t;
      cin >> t;
      h[t-1] = 1;
    }

    for(int i = 0; i < k; ++i) {
      cin >> u[i] >> v[i];
      u[i]--;
      v[i]--;
    }

    int bone = 0;
    for(int i = 0; i < k && !h[bone]; ++i) {
      if (bone == u[i]) {
        bone = v[i];
      } else if (bone == v[i]) {
        bone = u[i];
      }
    }

    cout << bone+1 << endl;
  }
}
