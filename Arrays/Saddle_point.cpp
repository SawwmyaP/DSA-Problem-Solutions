/*Problem:
Find the saddle point of a matrix. A saddle point is an element that is the smallest in its row and largest in its column.

Approach:
For each row, find the minimum element and then check whether it is the maximum element in its corresponding column.*/

#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    bool found = false;

    for(int i = 0; i < 3; i++) {
        int minRow = a[i][0];
        int col = 0;

        for(int j = 1; j < 3; j++) {
            if(a[i][j] < minRow) {
                minRow = a[i][j];
                col = j;
            }
        }

        bool saddle = true;
        for(int k = 0; k < 3; k++) {
            if(a[k][col] > minRow) {
                saddle = false;
                break;
            }
        }

        if(saddle) {
            cout << "Saddle Point: " << minRow;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "No Saddle Point";

    return 0;
}