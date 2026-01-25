/*Problem:
Given two strings, check whether the second string is a rotation of the first string.

Approach:
Concatenate the first string with itself and check whether the second string exists as a substring in the concatenated string.*/

#include <iostream>
using namespace std;

int main() {
    string s1 = "abcd";
    string s2 = "cdab";

    if(s1.length() == s2.length() && (s1 + s1).find(s2) != string::npos)
        cout << "Rotation";
    else
        cout << "Not Rotation";

    return 0;
}