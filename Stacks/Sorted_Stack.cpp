/*Problem:
Given a stack of integers, sort the stack in ascending order using only stack operations. No extra data structures (like arrays) are allowed.

Approach:
Use recursion to pop elements one by one and insert each element back into the stack at its correct sorted position.
The stack gets sorted during the recursive backtracking phase.*/

#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, x);
}

int main() {
    stack<int> st;
    st.push(30);
    st.push(10);
    st.push(20);
    st.push(5);

    sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}