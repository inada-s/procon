#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


int distance(string s, const string& t) {
  if (s == t) return 0;

  for(int i = 0; i < s.size(); ++i) {
    rotate(s.begin(), s.begin() + 1, s.end());
    if (s == t) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  int n;
  while(cin >> n) {
    vector<string> s(n);
    for(int i = 0; i < n; ++i) {
      cin >> s[i];
    }

    int ans = 1 << 30;
    for(int i = 0; i < n; ++i) {
      int tmp = 0;
      for(int j = 0; j < n; ++j) {
        int d = distance(s[j], s[i]);
        if (d == -1) {
          cout << -1 << endl;
          return 0;
        }
        tmp += d;
      }
      ans = min(ans, tmp);
    }
    cout << ans << endl;
  }
}
