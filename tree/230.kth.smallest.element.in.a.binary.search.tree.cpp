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
    int kth = -1;

    int kthSmallest(TreeNode* root, int k) {
        this->dfs(root, k);
        return this->kth;
    }

    int dfs(TreeNode *node, int k) {
        if (!node) return 0;

        // get the number of nodes on the left
        int left = this->dfs(node->left, k);

        // if kth smallest is in the left tree
        if (left < 0) return left;

        // if kth smallest is the current node
        if (left == k - 1) {
            kth = node->val;
            return -1;
        }

        // if kth smallest is in the right tree
        int right = this->dfs(node->right, k - left - 1);
        if (right < 0) return right;

        // if kth smallest not in this tree
        return left + right + 1;
    }
};
