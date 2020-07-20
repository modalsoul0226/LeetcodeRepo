/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (!root) return preorder;

        // init stack
        stack<TreeNode *> nodes;
        nodes.push(root);

        // dfs
        while (!nodes.empty()) {
            // extract a node
            TreeNode *node = nodes.top();
            nodes.pop();

            preorder.push_back(node->val);

            // push children
            if (node->right) nodes.push(node->right);
            if (node->left) nodes.push(node->left);
        }

        return preorder;
    }
};
