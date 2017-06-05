#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
 
int main() {
  int n;
  string s;
  while(cin >> n) {
    cin >> s;
    int a = count(s.begin(), s.end(), '1');
    int b = count(s.begin(), s.end(), '2');
    int c = count(s.begin(), s.end(), '3');
    int d = count(s.begin(), s.end(), '4');
    int x = max(max(a, b), max(c, d));
    int y = min(min(a, b), min(c, d));
    cout << x << " " << y << endl;
  }
}
