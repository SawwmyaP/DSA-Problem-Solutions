/* Problem:
Move all zeroes in an array to the end while maintaining the order of non-zero elements.

Approach:
Use a pointer to place non-zero elements at the front and fill the remaining positions with zeroes. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {0,1,0,3,12};
    int index = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0)
            nums[index++] = nums[i];
    }

    while(index < nums.size())
        nums[index++] = 0;

    for(int x : nums)
        cout << x << " ";
    return 0;
}