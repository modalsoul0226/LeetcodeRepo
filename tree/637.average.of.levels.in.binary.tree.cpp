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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgs;
        if (!root) return avgs;

        // init queue
        queue<TreeNode *> nodes;
        nodes.push(root);

        // bfs
        while (!nodes.empty()) {
            double sum = 0;
            int num = nodes.size();

            for (int i = 0; i < num; i++) {
                auto node = nodes.front();
                nodes.pop();

                // update average
                sum += node->val;

                // push children
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }

            // push the average for current level
            avgs.push_back(sum / num);
        }

        return avgs;
    }
};
