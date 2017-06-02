#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  int n, m, k;
  while(cin >> n >> m >> k) {
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int ans = 1 << 20;
    for(int i = 0; i < n; ++i) {
      if (a[i] && a[i] <= k) {
        ans = min(ans, abs(i - (m-1)));
      }
    }
    cout << ans * 10 << endl;
  }
}
