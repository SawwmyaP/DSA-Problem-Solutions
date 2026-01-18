/*Problem:
Given an integer n, print a center-aligned star pyramid consisting of n rows using the * symbol

Approach:
Use nested loops to print spaces followed by stars for each row.
The number of spaces decreases and the number of stars increases as the row number increases, forming a pyramid shape*/

#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n - i; space++) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; star++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}