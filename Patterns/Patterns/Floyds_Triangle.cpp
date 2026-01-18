/* Problem: 
Given an integer n, print Floyd’s Triangle consisting of n rows, where numbers are printed continuously starting from 1 in a right-angled triangular form.

Approach:
Use two nested loops to print the pattern.
Maintain a counter starting from 1 and increment it after printing each number.
The outer loop controls the number of rows, while the inner loop controls the number of elements in each row.
*/

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int num = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}