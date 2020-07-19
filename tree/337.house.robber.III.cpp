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
    int rob(TreeNode* root) {
        auto [max1, max2] = this->robMoneyPossibleSolutions(root);
        return max(max1, max2);
    }

    /**
     * Return the maximum amount of money either the thief robs
     * the root or not.
     *
     * @param t: the root node
     * @return: the first number is the maximum amount of money
     * if theif robs the root, the other one is if he doesn't.
     */
    tuple<int, int> robMoneyPossibleSolutions(TreeNode *t) {
        // 0 profit if no houses to rob
        if (!t) return {0, 0};

        // rob neighbors
        auto [l1, l2] = this->robMoneyPossibleSolutions(t->left);
        auto [r1, r2] = this->robMoneyPossibleSolutions(t->right);

        // if rob the root
        int rr = t->val + l2 + r2;
        // if doesn't rob the root
        // int drr = max({l1 + r1, l1 + r2, l2 + r1, l2 + r2});
        int drr = max(l1, l2) + max(r1, r2);
        
        return {rr, drr};
    }
};
