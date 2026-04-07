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

Node* LCA(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->data == p || root->data == q)
        return root;

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node* ans = LCA(root, 4, 5);

    if (ans)
        cout << ans->data;

    return 0;
}
