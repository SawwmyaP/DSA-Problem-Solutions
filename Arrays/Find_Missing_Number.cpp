/* Problem:
An array contains numbers from 1 to n with one number missing. Find the missing number.

Approach:
Calculate the expected sum of numbers from 1 to n and subtract the actual sum of the array.*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    int total = n * (n + 1) / 2;
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    cout << "Missing Number: " << total - sum;
    return 0;
}