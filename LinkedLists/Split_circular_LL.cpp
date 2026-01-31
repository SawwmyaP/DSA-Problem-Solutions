/*Problem:
Given a circular linked list, split it into two circular linked lists:
  If the number of nodes is even, both halves have equal nodes
  If odd, the first list gets one extra node
  
Approach:
Use slow and fast pointers to find the middle of the circular list.
Break the list at the middle and adjust pointers to form two circular halves.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitCircularList(Node* head, Node** head1, Node** head2) {
    if (!head || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1 = head;
    *head2 = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

void printCircularList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node* head = new Node{1, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{3, NULL};
    Node* fourth = new Node{4, NULL};
    Node* fifth = new Node{5, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head; // circular

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitCircularList(head, &head1, &head2);

    printCircularList(head1);
    cout << endl;
    printCircularList(head2);

    return 0;
}