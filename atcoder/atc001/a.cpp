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

int main() {
  int w, h;
  while(cin >> h >> w) {
    vector<string> m(h);
    for(int i = 0; i < h; ++i) {
      cin >> m[i];
    }

    function<bool(int,int)> dfs;
    dfs = [&](int x, int y) -> bool {
      if (m[y][x] == 'g') return true;
      if (m[y][x] == '#') return false;
      m[y][x] = '#';
      for (int d = 0; d < 4; ++d) {
        int nx = x;
        int ny = y;
        if (d == 0) nx++;
        if (d == 1) ny++;
        if (d == 2) nx--;
        if (d == 3) ny--;
        if (0 <= nx && nx < w && 0 <= ny && ny < h) {
          if (dfs(nx, ny)) {
            return true;
          }
        }
      }
      return false;
    };

    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        if (m[i][j] == 's') {
          if (dfs(j, i)) {
            cout << "Yes" << endl;
          } else {
            cout << "No" << endl;
          }
          break;
        }
      }
    }
  }
  return 0;
}
