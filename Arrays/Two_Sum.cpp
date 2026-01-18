/* Problem:
Given an array of integers and a target value, find the indices of the two numbers such that they add up to the target.

Approach:
Traverse the array and use a hash map to store visited elements. For each element, check if the required complement exists in the map. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    unordered_map<int,int> mp;

    for(int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if(mp.count(rem)) {
            cout << mp[rem] << " " << i;
            break;
        }
        mp[nums[i]] = i;
    }
    return 0;
}