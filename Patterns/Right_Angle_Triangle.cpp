/*Problem:
Print a right-angled triangle pattern where the number of stars increases row-wise.

Approach:
For each row i, print i stars using an inner loop. */

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}