/* Problem:
Find the element that appears more than ⌊n/2⌋ times in the array.

Approach:
Use Moore’s Voting Algorithm to find the majority element in linear time. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {3,2,3};
    int count = 0, candidate = 0;

    for(int num : nums) {
        if(count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }

    cout << candidate;
    return 0;
}