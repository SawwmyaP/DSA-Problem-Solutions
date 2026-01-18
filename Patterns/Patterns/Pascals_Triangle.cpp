/* Problem:
Given an integer n, print Pascal’s Triangle with n rows, where each element is the sum of the two elements above it and the first and last elements of every row are 1.

Approach:
Generate the triangle row by row using nested loops.
Start each row with 1 and compute subsequent values using the mathematical relation based on the previous value to avoid factorial calculations. */

#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {
        int val = 1;
        for (int j = 0; j <= i; j++) {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }

    return 0;
}