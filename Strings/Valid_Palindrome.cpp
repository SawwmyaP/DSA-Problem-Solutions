/*Problem:
Check whether a string is a palindrome considering only alphanumeric characters and ignoring case.

Approach:
Filter the string to keep only alphanumeric characters, convert to lowercase, and compare it with its reverse.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "A man, a plan, a canal: Panama";
    string t = "";

    for(char c : s)
        if(isalnum(c))
            t += tolower(c);

    string rev = t;
    reverse(rev.begin(), rev.end());

    cout << (t == rev);
    return 0;
}