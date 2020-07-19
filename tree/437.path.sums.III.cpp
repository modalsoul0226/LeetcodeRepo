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
    // number of paths
    int acc = 0;
    int target = 0;
    unordered_map<int, int> prefixSums;

    int pathSum(TreeNode* root, int sum) {
        // init
        this->target = sum;

        unordered_map<int, int> prefixSums = {{0, 1}};
        this->prefixSums = prefixSums;
        
        // dfs
        this->pathSumToNode(root, 0);
        
        return this->acc;
    }

    /**
     * Count the number of paths that sum to the given target.
     */
    void pathSumToNode(TreeNode *node, int currSum) {
        if (!node) return;

        // update current sum
        currSum += node->val;

        // check if there's a path from a previous node that sums up to target
        int prevSum = currSum - this->target;
        if (this->prefixSums.find(prevSum) != this->prefixSums.end())
            this->acc += this->prefixSums[prevSum];
        
        // register the current sum to prefix sums
        if (this->prefixSums.find(currSum) != this->prefixSums.end())
            this->prefixSums[currSum]++;
        else
            this->prefixSums[currSum] = 1;
        
        // visit children
        this->pathSumToNode(node->left, currSum);
        this->pathSumToNode(node->right, currSum);

        // de-register the curr sum from prefix sums beforing returning to parent
        // such that the siblings won't see it
        this->prefixSums[currSum]--;
    }
};
