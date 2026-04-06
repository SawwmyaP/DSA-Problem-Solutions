#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (!root) return 2; // null nodes are covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If any child is not covered, place camera
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Else, not covered
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};
