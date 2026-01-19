/*Problem:
Find the index of the first non-repeating character in a string.

Approach:
Count the frequency of each character, then traverse the string to find the first character with frequency one.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "leetcode";
    unordered_map<char,int> freq;

    for(char c : s)
        freq[c]++;

    for(int i = 0; i < s.size(); i++) {
        if(freq[s[i]] == 1) {
            cout << i;
            break;
        }
    }
    return 0;
}