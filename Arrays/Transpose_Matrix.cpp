/*Problem:
Find the transpose of a given matrix.

Approach:
Interchange rows and columns by assigning element at position (i, j) to (j, i) */

#include <iostream>
using namespace std;

int main() {
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int t[3][2];

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            t[j][i] = a[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }

    return 0;
}