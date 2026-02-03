/*Problem:
Implement a stack using an array and perform push and pop operations.

Approach:
Maintain a top variable to track the stack’s top element.
Increment top for push and decrement for pop.*/

#include <iostream>
using namespace std;

#define MAX 5

int main() {
    int stack[MAX], top = -1;

    // Push elements
    for(int i = 0; i < MAX; i++) {
        stack[++top] = i + 1;
    }

    // Pop elements
    while(top != -1) {
        cout << stack[top--] << " ";
    }

    return 0;
}