#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution {
public:
    int count = 0;

    void dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& mp) {
        if (!node) return;
      
        currSum += node->val;
        if (mp.find(currSum - target) != mp.end()) {
            count += mp[currSum - target];
        }

        mp[currSum]++;

        dfs(node->left, currSum, target, mp);
        dfs(node->right, currSum, target, mp);

        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;

        dfs(root, 0, targetSum, mp);
        return count;
    }
};
