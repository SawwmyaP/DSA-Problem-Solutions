/* Problem:
Given an integer array, find the contiguous subarray with the maximum sum.

Approach:
Use Kadane’s Algorithm by keeping track of the current sum and maximum sum while traversing the array. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = nums[0], currSum = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }

    cout << maxSum;
    return 0;
}