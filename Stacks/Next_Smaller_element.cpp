/*Problem:
Given an array of integers, find the next smaller element to the right for each element.
If no such element exists, print -1.

Approach:
Traverse the array from right to left using a stack.
Pop elements from the stack that are greater than or equal to the current element.
The stack top gives the next smaller element.*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n], ans[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= a[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(a[i]);
    }

    cout << "Next Smaller Elements: ";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}