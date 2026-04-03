#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int check(Node* root) {
    if (root == NULL) return 0;

    int left = check(root->left);
    if (left == -1) return -1;

    int right = check(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}

bool isBalanced(Node* root) {
    return check(root) != -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3); // unbalanced example

    if (isBalanced(root))
        cout << "Tree is Balanced";
    else
        cout << "Tree is NOT Balanced";
  
    return 0;
}
