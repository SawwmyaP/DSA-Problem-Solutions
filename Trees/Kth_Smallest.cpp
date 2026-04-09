#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(TreeNode* root, int &k, int &ans) {
    if (!root) return;

    inorder(root->left, k, ans);

    k--;
    if (k == 0) {
        ans = root->val;
        return;
    }

    inorder(root->right, k, ans);
}

int main() {
    int n, x, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    TreeNode* root = NULL;
    cout << "Enter BST values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter k: ";
    cin >> k;

    int ans = -1;
    inorder(root, k, ans);

    cout << "Kth Smallest Element: " << ans << endl;

    return 0;
}
