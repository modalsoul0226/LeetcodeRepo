/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        else if (!root->left && !root->right) return root;
        else {
            TreeNode *tmp = root->left;
            
            root->left = invertTree(root->right);
            root->right = invertTree(tmp);
            
            return root;
        }
    }
};