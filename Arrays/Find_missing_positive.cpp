/*Problem:
Given an unsorted integer array, find the smallest missing positive integer.
You must run in O(n) time and use constant extra space.

Approach:
Place each number x at index x−1 using swapping if it lies in range [1, n].
Traverse the array to find the first index where arr[i] ≠ i+1.*/

#include <iostream>
using namespace std;

int firstMissingPositive(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "First Missing Positive: " << firstMissingPositive(nums, n);
    return 0;
}