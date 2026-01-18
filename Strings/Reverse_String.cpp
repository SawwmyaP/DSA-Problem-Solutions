/*Problem:
Reverse the given string.

Approach:
Use two pointers or the built-in reverse function to reverse the string in-place.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello";

    reverse(s.begin(), s.end());

    cout << s;
    return 0;
}