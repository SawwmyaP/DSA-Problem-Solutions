/*Problem:
Given a sorted singly linked list, remove all duplicate elements such that each element appears only once.

Approach:
Since the list is sorted, duplicate values will be adjacent.
Traverse the list and compare the current node with the next node.
If both have the same value, skip the next node.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Node* removeDuplicates(Node* head) {
    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    int n, value;
    cout << "Enter number of nodes (sorted list): ";
    cin >> n;

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

    head = removeDuplicates(head);

    cout << "Linked List after removing duplicates:\n";
    display(head);

    return 0;
}
