#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// a, b, c, d
// i = 0
// a-b, b-a
//
// sample3.
// 1, 3
// => -2, 4
// gcd(-2, 4) = 2
//
// 15-5, 5-10
// gcd(10, -5) = 5
//
// 偶数と偶数 -> 偶数
// 偶数と奇数 -> 奇数
//
// 偶奇 => 奇奇
// 偶偶奇 => 偶奇奇 => 偶偶偶
// 偶偶偶奇 => 偶偶奇奇 => 偶偶奇奇 => 偶偶偶偶
// 奇偶偶 => 奇奇偶 => 偶偶偶 
// 奇偶奇 => 奇奇奇 => 偶偶奇 => 偶奇奇 => 偶偶偶

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  while(cin >> n) {
    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long g = a[0];
    for (int i = 0; i < n; ++i) {
      g = gcd(g, a[i]);
    }

    if (g > 1) {
      cout << "YES" << endl;
      cout << "0" << endl;
      continue;
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
      while (a[i] & 1) {
        ans++;
        long long x = a[i] - a[i+1];
        long long y = a[i] + a[i+1];
        a[i] = x;
        a[i+1] = y;
      }
    }

    if (a[n - 1] & 1) {
      ans += 2;
    }

    cout << "YES" << endl;
    cout << ans << endl;
  }
}
