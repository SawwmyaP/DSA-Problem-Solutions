/*Problem:
Rotate a given square matrix by 90 degrees in clockwise direction.

Approach:
First find the transpose of the matrix and then reverse each row to obtain the rotated matrix.*/

#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Transpose
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            swap(a[i][j], a[j][i]);
        }
    }

    // Reverse rows
    for(int i = 0; i < 3; i++) {
        int start = 0, end = 2;
        while(start < end) {
            swap(a[i][start], a[i][end]);
            start++;
            end--;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}