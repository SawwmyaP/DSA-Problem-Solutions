/*Problem:
Given an integer n, print a hollow diamond pattern of height 2n−1 using stars.

Approach:
Construct the upper and lower halves separately. Print stars only at the boundaries of the diamond while filling the inner space with spaces*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;

    // Upper half
    for(int i = 1; i <= n; i++) {
        for(int s = 1; s <= n - i; s++)
            cout << " ";
        cout << "*";
        if(i > 1) {
            for(int s = 1; s <= 2*i - 3; s++)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }

    // Lower half
    for(int i = n - 1; i >= 1; i--) {
        for(int s = 1; s <= n - i; s++)
            cout << " ";
        cout << "*";
        if(i > 1) {
            for(int s = 1; s <= 2*i - 3; s++)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}