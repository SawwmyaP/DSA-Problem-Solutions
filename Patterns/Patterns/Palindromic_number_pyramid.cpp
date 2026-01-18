/* Problem:
Given an integer n, print a palindromic number pyramid where numbers decrease to 1 and then increase back.

Approach:
For each row, print leading spaces followed by a decreasing sequence of numbers and then an increasing sequence to form a palindrome.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        // Spaces
        for(int s = 1; s <= n - i; s++)
            cout << " ";

        // Descending numbers
        for(int j = i; j >= 1; j--)
            cout << j;

        // Ascending numbers
        for(int j = 2; j <= i; j++)
            cout << j;

        cout << endl;
    }

    return 0;
}