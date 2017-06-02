/*
 * A wise man told Kerem "Different is good" once, so Kerem wants all things in his life to be different.
 *
 * Kerem recently got a string s consisting of lowercase English letters.
 * Since Kerem likes it when things are different, he wants all substrings of his string s to be distinct.
 * Substring is a string formed by some number of consecutive characters of the string.
 * For example, string "aba" has substrings "" (empty substring), "a", "b", "a", "ab", "ba", "aba".
 *
 * If string s has at least two equal substrings then Kerem will change characters at some positions to some other lowercase English letters.
 * Changing characters is a very tiring job, so Kerem want to perform as few changes as possible.
 *
 * Your task is to find the minimum number of changes needed to make all the substrings of the given string distinct, or determine that it is impossible.
 *
 * Input
 * The first line of the input contains an integer n (1 ≤ n ≤ 100 000) — the length of the string s.
 * The second line contains the string s of length n consisting of only lowercase English letters.
 *
 * Output
 * If it's impossible to change the string s such that all its substring are distinct print -1. Otherwise print the minimum required number of changes.
 *
 * Examples
 * input
 * 2
 * aa
 * output
 * 1
 *
 * input
 * 4
 * koko
 * output
 * 2
 *
 * input
 * 5
 * murat
 * output
 * 0
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
    int n; string s;
    cin >> n;
    cin >> s;

    if(n > 26) {
        cout << "-1" << endl;
    } else {
        int ans = 0;
        int cnt[26] = {0};
        for(char c : s) if(cnt[c - 'a']++) ans++;
        cout << ans << endl;
    }

}
