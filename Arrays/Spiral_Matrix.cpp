/*Problem:
Print the elements of a matrix in spiral order.

Approach:
Use four boundaries (top, bottom, left, right) and traverse the matrix layer by layer in spiral form.*/

#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int top = 0, bottom = 2, left = 0, right = 2;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++)
            cout << a[top][i] << " ";
        top++;

        for(int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";
        right--;

        for(int i = right; i >= left; i--)
            cout << a[bottom][i] << " ";
        bottom--;

        for(int i = bottom; i >= top; i--)
            cout << a[i][left] << " ";
        left++;
    }

    return 0;
}