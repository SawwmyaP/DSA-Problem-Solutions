/*Problem:
Given a singly linked list and an integer key, check whether the key is present in the linked list.

Approach:
Traverse the linked list node by node.
If the data of any node matches the key, return true.
If the end is reached without finding the key, return false.*/

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

bool searchElement(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

    cout << "Enter element to search: ";
    cin >> key;

    if (searchElement(head, key))
        cout << "Element found in the linked list.";
    else
        cout << "Element not found in the linked list.";

    return 0;
}