#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// ab -> bba : 1
// aab -> abba -> bbaba -> bbbbaa : 3
// aaab -> aabba -> abbaba -> bbababa -> bbbbaaba -> bbbbabbaa -> bbbbbbabaa -> bbbbbbbbaaa : 7
// 最終型は, bbbbbbbaaaaa といったかたちしか無い
// 最初にみつかるabをbbaにするのが良さそう
// bより左にあるaをすべて右に動かす操作と考えれる このときbの数が増える
// a*n + b*m : (2^n-1) * m
int hoge() {
  string s;
  while(cin >> s) {
    int n = 0;
    auto t = string::npos;
    while((t = s.find("ab")) != string::npos) {
      s.replace(t, 2, "bba", 0, 3);
      cout << ">" << s << endl;
      n++;
    }
    cout << n << endl;
    cout << "--------------------" << endl;
  }
}

int main() {
  string s;
  while(cin >> s) {
    vector<pair<int, int> > ab;
    pair<int, int> p;
    bool flg = false;
    for(int i = 0; i < s.size(); ++i) {
      if (s[i] == 'a') {
        if (flg) {
          ab.push_back(p);
          p = make_pair(0, 0);
          flg = false;
        }
        p.first++;
      }
      if (s[i] == 'b') {
        p.second++;
        flg = true;
      }
    }

    if(p.first || p.second) {
        ab.push_back(p);
    }

    int a = 0;
    for(int i = 0; i < ab.size(); ++i) {
      (ab[i].first + a)
    }
  }
}

