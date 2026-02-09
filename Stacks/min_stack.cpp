/*Problem:
Design a stack that supports push, pop, top, and getMin() operations in O(1) time.

Approach:
Maintain an auxiliary stack to store minimum values.
When pushing, also push into minStack if it’s smaller or equal to current minimum.
Pop from minStack when the minimum element is removed.*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minStack;

public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if (s.top() == minStack.top())
            minStack.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin();
    return 0;
}