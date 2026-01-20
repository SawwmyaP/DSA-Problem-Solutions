/* Problem:
Detect whether a cycle exists in a linked list.

Approach:
Use Floyd’s Cycle Detection Algorithm (slow & fast pointers) */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = head; // cycle

    cout << hasCycle(head);
    return 0;
}