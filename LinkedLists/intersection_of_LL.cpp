/*Problem:
Given two sorted singly linked lists, find their intersection.
The intersection list should contain only common elements present in both lists and must be in sorted order.
Create a new linked list without modifying the original lists.

Approach:
Traverse both lists using two pointers and compare node values.
If values match, add to result; otherwise move the pointer with smaller value. */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    return n;
}

Node* findIntersection(Node* head1, Node* head2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = createNode(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } 
        else if (head1->data < head2->data) {
            head1 = head1->next;
        } 
        else {
            head2 = head2->next;
        }
    }
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);

    Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    Node* result = findIntersection(head1, head2);
    printList(result);

    return 0;
}