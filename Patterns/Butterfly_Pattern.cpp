/*Problem:
Given an integer n, print a butterfly-shaped star pattern that is symmetric both vertically and horizontally.

Approach:
Divide the pattern into an upper and lower half. For each row, print stars on both sides and spaces in between, increasing and then decreasing the number of stars to maintain symmetry.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;

    // Upper half
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            cout << "*";
        for(int j = 1; j <= 2*(n-i); j++)
            cout << " ";
        for(int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    // Lower half
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++)
            cout << "*";
        for(int j = 1; j <= 2*(n-i); j++)
            cout << " ";
        for(int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}