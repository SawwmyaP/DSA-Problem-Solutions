/*Problem:
Given a singly linked list, reverse the nodes of the list k at a time and return the modified list.
If the number of nodes is not a multiple of k, leave the remaining nodes as they are.

Approach:
Check if at least k nodes exist; if yes, reverse the first k nodes using pointer manipulation.
Recursively process the remaining list and attach it to the reversed group.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;
    Node* temp = head;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k) return head;

    count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverseKGroup(curr, k);
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    head = reverseKGroup(head, k);

    cout << "Reversed List: ";
    printList(head);
    return 0;
}