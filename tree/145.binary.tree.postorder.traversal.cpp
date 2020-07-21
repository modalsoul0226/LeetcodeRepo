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
    vector<int> postorderTraversal(TreeNode* root) {
        // nodes in post order
        vector<int> postorder;
        if (!root) return postorder;

        // init stacks
        stack<TreeNode *> nodes;
        stack<int> visited;

        nodes.push(root);
        visited.push(0);

        while (!nodes.empty()) {
            // extract a node, and a corresponding boolean
            // that indicates if we've visited this node before
            TreeNode *node = nodes.top();
            int visit = visited.top();

            nodes.pop();
            visited.pop();

            // push to the result postorder vector if we've visited this node
            // otherwise, push back to nodes and set the flag
            if (visit) {
                postorder.push_back(node->val);
                continue;
            } else {
                nodes.push(node);
                visited.push(1);
            }

            // push the right child
            if (node->right) {
                nodes.push(node->right);
                visited.push(0);
            }

            // push the left child
            if (node->left) {
                nodes.push(node->left);
                visited.push(0);
            }
        }
        
        return postorder;
    }
};
