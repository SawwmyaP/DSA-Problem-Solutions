#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree() {
    cout << "Enter values (-1 for NULL): ";
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> arr;
    int x;
    while (ss >> x) arr.push_back(x);

    if (arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(node->val);

        if (node->left) q.push({node->left, {x-1, y+1}});
        if (node->right) q.push({node->right, {x+1, y+1}});
    }

    cout << "Vertical Traversal:\n";
    for (auto p : nodes) {
        for (auto q : p.second) {
            for (auto val : q.second)
                cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = buildTree();
    verticalTraversal(root);
}
