/* Problem:
Given a queue of integers, reverse the queue.

Approach:
Push all elements of queue into a stack.
Pop from stack and push back into queue.*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    queue<int> q;
    stack<int> s;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    // Reverse process
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    cout << "Reversed Queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}