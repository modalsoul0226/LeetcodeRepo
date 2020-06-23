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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        // global maximum
        int maxDepth = 1;

        // stack for tree nodes and corresponding depths
        stack<TreeNode *> nodes;
        nodes.push(root);        
        
        stack<int> depths;
        depths.push(1);

        // local vars
        TreeNode *curr;
        int depth;

        // reiterate each node
        while (!nodes.empty()) {
            curr = nodes.top();
            nodes.pop();
            
            depth = depths.top();
            depths.pop();
            
            if (curr->right) {
                nodes.push(curr->right);
                depths.push(depth + 1);
            }
            
            if (curr->left) {
                nodes.push(curr->left);
                depths.push(depth + 1);
            }
            
            if (!(curr->left || curr->right))
                maxDepth = maxDepth > depth ? maxDepth : depth;
        }
        
        return maxDepth;
    }
};
