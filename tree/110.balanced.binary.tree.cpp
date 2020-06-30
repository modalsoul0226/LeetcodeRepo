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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        return this->depths(root) != -1;
    }

    /**
     * Returns -1 if not balanced. Else returns the
     * depth.
     */
    int depths(TreeNode *node) {
        int left = 0;
        int right = 0;
        
        if (node->left) left = this->depths(node->left);
        if (node->right) right = this->depths(node->right);
        
        if (left == -1 || right == -1)
            // if one of the subtree is not balanced
            return -1;
        else if (abs(left - right) > 1)
            // differ more than 1
            return -1;
        else
            // return depth
            return max(left, right) + 1;
    }
    
//     int diffInDepths(TreeNode *root) {
//         int maxDepth = INT_MIN;
//         int minDepth = INT_MAX;
        
//         stack<TreeNode *> nodes;
//         stack<int> depths;
        
//         nodes.push(root);
//         depths.push(1);
        
//         TreeNode *curr;
//         int depth;
//         while (!nodes.empty()){
//             curr = nodes.top();
//             depth = depths.top();
            
//             nodes.pop();
//             depths.pop();
            
//             if (curr->right) {
//                 nodes.push(curr->right);
//                 depths.push(depth + 1);
//             } else {
//                 minDepth = depth < minDepth ? depth : minDepth;
//             }
            
//             if (curr->left) {
//                 nodes.push(curr->left);
//                 depths.push(depth + 1);
//             } else {
//                 minDepth = depth < minDepth ? depth : minDepth;
//             }
            
//             if (!(curr->left || curr->right))
//                 maxDepth = depth > maxDepth ? depth : maxDepth;
//         }
        
//         return maxDepth - minDepth;
//     }
};
