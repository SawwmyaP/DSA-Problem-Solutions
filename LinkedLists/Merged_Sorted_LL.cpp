/* Problem:
Merge two sorted linked lists into one sorted list.

Approach:
Compare nodes from both lists and attach the smaller one
to the result list. */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

Node* mergeLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while(l1 && l2) {
        if(l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

int main() {
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    Node* l2 = new Node(2);
    l2->next = new Node(4);

    Node* res = mergeLists(l1, l2);
    while(res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}