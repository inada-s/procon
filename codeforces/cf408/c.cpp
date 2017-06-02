#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);

  int n;
  while(cin >> n) {
    vector<int> a(n);
    vector<vector<int>> e(n);

    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    for(int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      e[u].push_back(v);
      e[v].push_back(u);
    }

    int m = *max_element(a.begin(), a.end());
    int x = count(a.begin(), a.end(), m);
    int y = count(a.begin(), a.end(), m-1);
    int ans = m + 2;

    for(int i = 0; i < n; ++i) {
      int z = 0;
      int w = 0;

      if (a[i] == m) z++;
      if (a[i] == m-1) w++;

      for(int j : e[i]) {
        if (a[j] == m) z++;
        if (a[j] == m-1) w++;
      }
    }

      for(int j : e[i]) {
        if (a[i] == m && a[j] == m) {
          ans = max(ans, m + 1);
        }

        for(int k : e[j]) {
          if (k != i) {
            if (a[i] == m && a[j] == m && a[k] == m) {
              ans = max(ans, m + 2);
            }

            if (a[i] == m && a[k] == m) {
              ans = max(ans, m + 1);
            }
          }
        }
      }
    }

    cout << ans << endl;
  }
}
