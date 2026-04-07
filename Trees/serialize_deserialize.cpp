#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree() {
    cout << "Enter values (level order, -1 for NULL): ";

    vector<int> arr;
    int x;
    string line;
    getline(cin, line);
    stringstream ss(line);

    while (ss >> x) {
        arr.push_back(x);
    }

    if (arr.size() == 0 || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i >= arr.size()) break;

        if (arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        string result = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null ";
            }
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string val;

        ss >> val;
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left
            if (!(ss >> val)) break;
            if (val != "null") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Right
            if (!(ss >> val)) break;
            if (val != "null") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Tree (level order): ";

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = buildTree();

    Codec codec;

    // Serialize
    string data = codec.serialize(root);
    cout << "\nSerialized Tree:\n" << data << endl;

    // Deserialize
    TreeNode* newRoot = codec.deserialize(data);
    cout << "\nAfter Deserialization:\n";
    printTree(newRoot);

    return 0;
}
