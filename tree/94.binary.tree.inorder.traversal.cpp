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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode *> nodes;

        // dfs
        while (root || !nodes.empty()) {
            while (root) {
                nodes.push(root);
                root = root->left;
            }

            // extract a node
            TreeNode *node = nodes.top();
            nodes.pop();

            // the extracted node doesn't have a left child
            // so we can push it to the inorder list
            inorder.push_back(node->val);

            // proceed with its right child
            root = node->right;
        }

        return inorder;
    }
};
