#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int cnt(const string& s) {
  int n = 0;
  for(int i = 0; i < s.size() - 1; ++i) {
    if (s[i] == 'V' && s[i+1] == 'K') {
      n++;
    }
  }
  return n;
}

int main() {
  string s;
  while (cin >> s) {
    int ans = cnt(s);
    for(int i = 0; i < s.size(); ++i) {
      string t = s;
      if(t[i] == 'V') t[i] = 'K';
      else if(t[i] == 'K') t[i] = 'V';
      ans = max(ans, cnt(t));
    }
    cout << ans << endl;
  }
}
