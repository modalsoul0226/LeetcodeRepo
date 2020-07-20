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
    int findBottomLeftValue(TreeNode* root) {
        // the leftmost value
        int leftmost = -1;

        // init queue
        queue<TreeNode *> nodes;
        nodes.push(root);

        // bfs
        while (!nodes.empty()) {
            // number of nodes in the current level
            int num = nodes.size();

            // register the leftmost value of the current level
            leftmost = nodes.front()->val;

            // pop the nodes in current level
            // and push the children
            for (int i = 0; i < num; i++) {
                TreeNode *node = nodes.front();
                nodes.pop();

                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        }

        return leftmost;
    }
};
