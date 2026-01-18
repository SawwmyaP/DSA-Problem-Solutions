/* Problem:
Rotate an array to the right by k steps.

Approach:
Reverse the entire array, then reverse the first k elements and the remaining elements. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    k %= nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    for(int x : nums)
        cout << x << " ";
    return 0;
}