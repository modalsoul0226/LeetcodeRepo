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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        if (!root) return sum;
        
        if (root->left && isLeave(root->left)) sum += root->left->val;
        
        return sum + this->sumOfLeftLeaves(root->left) + this->sumOfLeftLeaves(root->right);
    }
    
    bool isLeave(TreeNode *node) {
        return !(node->left || node->right);
    }
};
