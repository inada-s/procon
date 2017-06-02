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
  string x, y;
  while (cin >> x >> y) {
    string z = y;
    bool imp = false;
    for (int i = 0; i < x.size(); ++i) {
      if (x[i] != y[i]) {
        z[i] = y[i];
        if (z[i] > x[i]) {
          imp = true;
        }
      }
    }

    if (imp) {
      cout << -1 << endl;
    } else {
      cout << z << endl;
    }
  }
}
