/* Problem:
Reverse a singly linked list.

Approach:
Iteratively reverse links using three pointers: previous, current, and next. */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = reverseList(head);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}