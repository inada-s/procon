/* Problem:
 * Every year, hundreds of people come to summer camps, they learn new algorithms and solve hard problems.
 * This is your first year at summer camp, and you are asked to solve the following problem.
 * All integers starting with 1 are written in one line. The prefix of these line is "123456789101112131415...".
 * Your task is to print the n-th digit of this string (digits are numbered starting with 1.
 */
#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    for(int i=0; i<=1000; ++i) {
        s += to_string(i);
    }
    int n;
    cin >> n;
    cout << s[n] << endl;
}
