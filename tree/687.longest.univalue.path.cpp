int speedUp = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    int globalMax = INT_MIN;

    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;

        this->longestUnivaluePathAcrossRoot(root);
        
        return this->globalMax;
    }
    
    int longestUnivaluePathAcrossRoot(TreeNode *node) {
        int sum = 0;
        int leftSum = 0;
        int rightSum = 0;

        if (!node)
            return sum;
        
        if (node->left) {
            int res = this->longestUnivaluePathAcrossRoot(node->left);

            if (node->val == node->left->val)
                leftSum = 1 + res;
        }
        
        if (node->right) {
            int res = this->longestUnivaluePathAcrossRoot(node->right);
            
            if (node->val == node->right->val)
                rightSum = 1 + res;
        }

        // compare with the global max
        sum = leftSum + rightSum;
        this->globalMax = max(sum, this->globalMax);

        return max(leftSum, rightSum);
    }
};
