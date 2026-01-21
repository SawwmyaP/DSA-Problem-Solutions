/* Problem:
Find the maximum product that can be obtained from any two elements in the array.

Approach:
Track the two largest and two smallest elements since negative numbers can also yield a maximum product.*/

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {-10, -3, 5, 6, -2};
    int n = 5;

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        //updating largest and second largest
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
        //Updating smallest and second smallest
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    int prod1 = max1 * max2;
    int prod2 = min1 * min2;

    cout << "Maximum Product = " << (prod1 > prod2 ? prod1 : prod2);
    return 0;
}