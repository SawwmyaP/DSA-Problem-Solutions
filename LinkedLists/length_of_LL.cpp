/*Problem:
Given the head of a singly linked list, find the number of nodes present in the list.

Approach:
Start from the head node and traverse the list until NULL is reached.
Maintain a counter and increment it for every node visited */

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

int findLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

    cout << "Length of Linked List: " << findLength(head);

    return 0;
}