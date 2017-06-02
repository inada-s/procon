#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  int n;
  string s;
  while(cin >> n) {
    while(s.size() < n) {
      s += "aabbaabbaabbaabb";
    }
    cout << s.substr(0, n) << endl;
  }
}
