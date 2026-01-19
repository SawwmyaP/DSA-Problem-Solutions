/*Problem:
Determine whether two strings are anagrams of each other.

Approach:
Sort both strings and compare them, or count character frequencies using a hash map.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "anagram", t = "nagaram";
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    cout << (s == t);
    return 0;
}