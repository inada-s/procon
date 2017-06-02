#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main() {
  int l, r;
  while(cin >> l >> r) {
    if (l == r) {
      cout << l << endl;
    } else {
      cout << 2 << endl;
    }
  }
}
