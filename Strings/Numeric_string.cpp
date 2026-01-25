/*Problem:
Given a string, check whether the string contains only numeric digits (0–9).

Approach:
Traverse each character of the string and verify that it lies between '0' and '9'; if any character is outside this range, the string does not contain only digits.*/

#include <iostream>
using namespace std;

bool onlyDigits(string s) {
    for(char c : s) {
        if(c < '0' || c > '9')
            return false;
    }
    return true;
}

int main() {
    string s = "12345";
    cout << (onlyDigits(s) ? "Yes" : "No");
    return 0;
}