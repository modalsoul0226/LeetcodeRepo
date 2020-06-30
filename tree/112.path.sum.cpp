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
    bool hasPathSum(TreeNode* root, int sum) {
        // sanity check
        if (!root) return false;

        // stacks
        stack<int> sums;
        stack<TreeNode *> nodes;
        
        nodes.push(root);
        sums.push(0);
        
        // traverse
        while (!nodes.empty()) {
            // pop
            auto curr_sum = sums.top();
            auto node = nodes.top();
            sums.pop();
            nodes.pop();
            
            // current sum
            curr_sum += node->val;
            
            // push
            if (node->right) {
                nodes.push(node->right);
                sums.push(curr_sum);
            }
            
            if (node->left) {
                nodes.push(node->left);
                sums.push(curr_sum);
            }
            
            if (!(node->left || node->right)) {
                if (curr_sum == sum)
                    return true;
            }
        }

        return false;
    }
};
