/*Problem:
Given an integer n, print a pyramid where each row contains numbers starting from 1 up to the row number.

Approach:
Use nested loops where the outer loop controls the rows and the inner loop prints numbers from 1 to the current row index.*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}