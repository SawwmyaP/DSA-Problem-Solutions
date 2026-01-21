/*Problem:
Given a sorted array, remove duplicate elements in-place and return the new length.

Approach:
Use a two-pointer technique where one pointer tracks unique elements and the other scans the array.*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3};
    int n = 5;

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    cout << "New Length: " << j + 1 << endl;
    for (int i = 0; i <= j; i++)
        cout << arr[i] << " ";

    return 0;
}