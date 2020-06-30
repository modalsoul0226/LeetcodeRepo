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
    int d = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        this->depth(root);
        return d;
    }
    
    int depth(TreeNode *node) {
        if (!node) return 0;

        int left = 0;
        int right = 0;
        
        if (node->left)
            left = 1 + this->depth(node->left);
        
        if (node->right)
            right = 1 + this->depth(node->right);

        d = max(left + right, d);
        
        return max(left, right);
    }
};
