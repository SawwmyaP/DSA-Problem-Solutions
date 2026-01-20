/* Problem:
Remove the Nth node from the end of a linked list.

Approach:
Use two pointers with a gap of N nodes. */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0);
    dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;

    for(int i = 0; i <= n; i++)
        first = first->next;

    while(first) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy.next;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = removeNthFromEnd(head, 2);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}