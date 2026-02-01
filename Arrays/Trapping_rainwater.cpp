/*Problem:
Given an array where each element represents elevation height, calculate how much rainwater can be trapped after rainfall.

Approach:
Use two pointers while maintaining left and right maximum heights.
At each step, trap water based on the smaller maximum and move the corresponding pointer inward.*/

#include <iostream>
using namespace std;

int trap(int height[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    int height[] = {4, 2, 0, 3, 2, 5};
    int n = sizeof(height) / sizeof(height[0]);

    cout << "Trapped Water: " << trap(height, n);
    return 0;
}