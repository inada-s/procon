#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  string s;
  while(cin >> s) {
    int d = 0;
    for(int i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - 1 - i]) {
        d++;
      }
    }
    if (d == 1 || (d == 0 && s.size() % 2 == 1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
