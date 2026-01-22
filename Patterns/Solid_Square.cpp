/*Problem Statement
Write a program to print a solid square pattern of stars of size n.

Approach:
Use two nested loops where both rows and columns run from 1 to n and print * for each position.*/

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}