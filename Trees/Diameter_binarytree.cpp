#include <iostream>
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

int diameterUtil(Node* root, int &diameter) {
    if (root == NULL) return 0;

    int left = diameterUtil(root->left, diameter);
    int right = diameterUtil(root->right, diameter);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << diameterOfBinaryTree(root);

    return 0;
}
