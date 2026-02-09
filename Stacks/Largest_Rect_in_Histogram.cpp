/*Problem:
Given an array representing heights of bars in a histogram, find the largest rectangular area that can be formed.

Approach:
Use a monotonic increasing stack to store indices of bars.
When a smaller bar appears, pop from stack and calculate area using the popped bar as the smallest height.
Keep updating the maximum area.*/

#include <iostream>
#include <stack>
using namespace std;

int largestRectangleArea(int heights[], int n) {
    stack<int> st;
    int maxArea = 0;
    int i = 0;

    while (i < n) {
        if (st.empty() || heights[st.top()] <= heights[i]) {
            st.push(i++);
        } else {
            int top = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
    }

    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        maxArea = max(maxArea, heights[top] * width);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << largestRectangleArea(heights, n);
    return 0;
}